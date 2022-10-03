% insert comment
clear all
rng default
Fs = 1000; % 取樣頻率 = 1000 Hz
t = 0:1/Fs:1-1/Fs; % 設定時間區段，以 0 為起始點，1-1/Fs 為結束點，以 1/Fs = 1/1000 為間隔
x = cos(2*pi*100*t) + randn(size(t)); % 創造頻率為 100 Hz 的正弦波訊號，用 randn 創造 1000 個雜訊值（每個訊號點各一個）
N = length(x); % 令 N 為 x 的總長
xdft = fft(x); % 將加入雜訊的正弦波訊號進行 Fast Fourier Transform 快速傅立葉轉換
xdft = xdft(1:N/2+1); 
% 因為傅立葉轉換後奇數值都是正複數，偶數值是負複數，正負複數2 個 2 個一對互為共軛複數
% 我們要取正數的部分，所以只取 1Hz 到 Nyquist frequency （採樣頻率的一半）
% 因為 0 為 dc ，其值代表訊號在 time domain 的總和，很大要先去除掉）
psdx = (1/(Fs*N)) * abs(xdft).^2; % 取值代入功率頻譜的密度公式，只取正頻率所以取平方
psdx(2:end-1) = 2*psdx(2:end-1); 
%這一步是考慮到去除部分頻譜的能量散失，所以要將取到的正頻率乘以 2 ，因為信號是實數，所以只用 DFT 的正頻率來計算幅度，
%以輸入訊號的長度來縮放 DFT，將 0 和Nyquist frequency 兩點以外的所有頻率乘以 2)
freq = 0:Fs/length(x):Fs/2; % 最後，以 0 為起始點，Fs/2 為結束點，以 Fs/length(x) 取樣頻率除以訊號長度為間隔作為畫 figure 的範圍
plot(freq, 10*log10(psdx)) % 分貝的計算方式，將頻率以 10 為對數取 log 乘以 10 ，可以得到分貝數
grid on % 繪圖
title('Periodogram Using FFT') % figure title 
xlabel('Frequency (Hz)') % x 軸單位
ylabel('Power/Frequency (dB/Hz)') % y 軸單位 
