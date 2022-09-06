/******************************************************************************
 *  Compilation:  javac HelloGoodbye.java
 *  Execution:    java HelloGoodbye Kevin Bob
 *
 *  Reads in two Names command-line arguments and prints "Hello Kevin and Bob" and "Goodbye Bob and Kevin"
 *
 *  % java HelloGoodbye Kevin Bob
 *  Hello Kevin and Bob.
 *  Goodbye Bob and Kevin.
 *
 *  Name:              Pei-An Chen
 *  Last modified:     September 6, 2022
 *  Purpose: Coursera Course Assignments
 *  Course: Algorithms, Part I (Princeton University)
 ******************************************************************************/
 


public class HelloGoodbye {
	public static void main( String [] args ){
		 System.out.print( "Hello " );
		 System.out.print( args[0] );
		 System.out.print( " and " );
		 System.out.println( args[1] + "." );
		 System.out.print( "Goodbuy " );
		 System.out.print( args[1] );
		 System.out.print( " and " );
		 System.out.println( args[0] + "." );
	
	}
}
