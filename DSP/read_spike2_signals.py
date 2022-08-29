pip install sonpy

try:
    from sonpy import lib as sp

    # Data storage and function finder
    DataReadFunctions = {
        sp.DataType.Adc: sp.SonFile.ReadInts,
        sp.DataType.EventFall: sp.SonFile.ReadEvents,
        sp.DataType.EventRise: sp.SonFile.ReadEvents,
        sp.DataType.EventBoth: sp.SonFile.ReadEvents,
        sp.DataType.Marker: sp.SonFile.ReadMarkers,
        sp.DataType.AdcMark: sp.SonFile.ReadWaveMarks,
        sp.DataType.RealMark: sp.SonFile.ReadRealMarks,
        sp.DataType.TextMark: sp.SonFile.ReadTextMarks,
        sp.DataType.RealWave: sp.SonFile.ReadFloats
    }
except:
    pass
  
 
# Deifine the function to get info in all channels
def get_all_channels_info(file_path):
    """
        Extract info from all channels in the smrx file. Returns a dictionary with
        valid smrx channel indexes as keys and the respective channel information as
        value.

        Parameters:
        -----------
        f: str Path to .smrx file
        """
    
    f = sp.SonFile(sName=str(file_path), bReadOnly=True)     
    n_channels = f.MaxChannels()
    return {
        i: get_channel_info(f, i) for i in range(n_channels)
        if f.ChannelType(i) != sp.DataType.Off
    }

# Deifine the function to get the specific info in each channel
def get_channel_info(f, smrx_ch_ind):
    """
    Extract info from smrx files

    Parameters:
    -----------
    f: str
        SonFile object.
    smrx_ch_ind: int
        Index of smrx channel. Does not match necessarily with extractor id.
    """

    nMax = 1 + int(f.ChannelMaxTime(smrx_ch_ind) / f.ChannelDivide(smrx_ch_ind))
    frame_offset = f.FirstTime(chan=smrx_ch_ind, tFrom=0, tUpto=nMax) / f.ChannelDivide(smrx_ch_ind)
    ch_info = {
        'type': f.ChannelType(smrx_ch_ind),           # Get the channel kind
        'ch_number': f.PhysicalChannel(smrx_ch_ind),  # Get the physical channel number associated with this channel
        'title': f.GetChannelTitle(smrx_ch_ind),      # Get the channel title
        'ideal_rate': f.GetIdealRate(smrx_ch_ind),    # Get the requested channel ideal rate
        'rate': 1 / (f.GetTimeBase() * f.ChannelDivide(smrx_ch_ind)),    # Get the requested channel real rate
        'max_time': f.ChannelMaxTime(smrx_ch_ind),    # Get the time of the last item in the channel (in clock ticks)
        'divide': f.ChannelDivide(smrx_ch_ind),       # Get the waveform sample interval in file clock ticks
        'time_base': f.GetTimeBase(),                 # Get how many seconds there are per clock tick
        'frame_offset': frame_offset,                 # Get frame offset
        'scale': f.GetChannelScale(smrx_ch_ind),      # Get the channel scale
        'offset': f.GetChannelOffset(smrx_ch_ind),    # Get the channel offset
        'unit': f.GetChannelUnits(smrx_ch_ind),       # Get the channel units
        'y_range': f.GetChannelYRange(smrx_ch_ind),   # Get a suggested Y range for the channel
        'comment': f.GetChannelComment(smrx_ch_ind),  # Get the comment associated with a channel
        'size_bytes:': f.ChannelBytes(smrx_ch_ind),   # Get an estimate of the data bytes stored for the channel
    }

    return ch_info


with open('filepathname.csv', newline='') as csvfile:

  # Read the file line-by-line
  rows = csv.reader(csvfile)
  
  for row in rows:
    prefile_path = row[0]  
    file_path = prefile_path[1:-1]
    print(file_path)
    
    get_all_channels_info(file_path)
    # get_channel_info
    
    
    MyFile = sp.SonFile(file_path, True)
    get_all_channels_info(file_path)
    
    if MyFile.GetOpenError() != 0:
        print("Error opening file:", sp.GetErrorString(MyFile.GetOpenError()))
        quit()
    

    for WaveChan in range(0,8):
        dMaxTime = MyFile.ChannelMaxTime(WaveChan) * MyFile.GetTimeBase()
        nSeconds = 0.0
        dSeconds = dMaxTime

        # Prepare for plotting
        dPeriod = MyFile.ChannelDivide(WaveChan) * MyFile.GetTimeBase()
        nPoints = floor(dSeconds / dPeriod)
        xPoints = np.arange(0, nPoints * dPeriod, dPeriod)

        # Read data
        WaveData = MyFile.ReadFloats(WaveChan, nPoints, 0)

        if len(WaveData) == 1 and WaveData[0] < 0:
            print("Error reading data:", sp.GetErrorString(int(WaveData[0])))
            quit()
        elif len(WaveData) == 0:
            print("No data read")
            quit()
        elif len(WaveData) != nPoints:
            print(
                "Bad number of points read, expected",
                str(nPoints),
                "but got",
                str(len(WaveData)),
            )
            quit()

        #Plot channel
        fig, ax = plt.subplots(figsize = (20, 10))
        ax.plot(xPoints, WaveData)

        ax.set_xlabel("Time (s)", fontsize = 'x-large', fontfamily = 'sans-serif', color = 'white', fontstyle = 'italic')
        ax.set_ylabel(MyFile.GetChannelUnits(WaveChan), fontsize = 10, fontfamily = 'sans-serif', color = 'blue', fontstyle = 'oblique')

        ax.set(
        #     xlabel="Time (s)",
        #     ylabel=MyFile.GetChannelUnits(WaveChan),
            title="Channel "
            + str(WaveChan)
            + " ("
            + MyFile.GetChannelTitle(WaveChan)
            + ")",
        )
        
        plt.show()
