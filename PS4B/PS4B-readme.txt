/**********************************************************************
 *                                                  
 *  PS3b: StringSound implementation and SFML audio output 
 **********************************************************************/

Name: Anson Cheang

Hours to complete assignment : 20 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes I did get the whole assignment to work successfully. since I can play
each key and they produce a unique sound

/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/

no I did not do the extra credits

/**********************************************************************
 *  Did you implement exceptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

yes, with checking if certain functions loses an item or not, or enqueued
correctly and dequeued correctly, like tic should always be full. Another
exception in the constructor with double as a parameter, making sure the
frequency is not 0 or below. Lastly sample shouldnt be empty, so there is
an exception there as well. then an exception in KSGuitarSim main, which
blocks incorrect inputs, essentially only inputs from the pdf works

The test for the exceptions are in test.cpp

/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

Yes I did implement the lambda expressions only for it to return samples.
like a portion of it to call the lambda expression inputting the i(for the keys)
then finding out the frequency within the lambda, the lambda then calls 
the makeSamples function from there. but overall I just followed the class
lecture notes pdf

/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/

yes it does, just followed what it told me to do when doing the make, since
its pretty obvious on what it is asking me to do.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/

Professor Daly
class discord
SFML website
Shriya Thakur
Class Notes

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

Audiopulse set up - James Daly helped
segment fault, did not set up the constructor correctly
audio sounds the same, its the sound doesnt store buffer, and sound buffer doesnt store sample
fixed, made the vector of vector of samples first, then use the for loop to make a vector of
unique pointer of soundBuffer, and a third for to make a vector of sound from the soundBuffer
some audio sounds the same - fixed, my variable was in int, for example 440 was supposed to be 440.0

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

 "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' " are the only input (not the quotations)
 
 there is a test.cpp, which is used to test StringSound.cpp, not CircularBuffer.cpp
 
 According to the rubric I was allowed to use SSLite as a base, as they say
 "transforming the SSLite version into a full 37 note player per assignment"
 
 if statements for exceptions

 switch is to check if the window is ever closed

