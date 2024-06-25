/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Anson Cheang
Hours to complete assignment: 6 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The Assignment has us make a linear feedback shift register, in which we
store the initial string of bit, and everytime it calls step it XOR the bits
in position (in test 1) 15, 13, 12, 10 or because I used vector position 
0, 2, 3, and 5. Then left shift and place the bit at the right most bit.
Generate does the same except return the int the bit it represent and does the
step k amount of time.

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/

I used vectors, which is a stl storage header, which is dynamically allocated
and inserted in sequence, plus the insert is done through push_back function as well.
The reason I selected it is because I needed it to be sequence, with each element
easily accessable, and vectors was the first one to pop into my head when thinking
of how to do this. 
 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/

In the second test I tested if it was out of bounds since the maximum number
of bits for an int is 32 bits, so I tested to see if it works if I type in 
less than 0 or greater than 32.
Test 3 I tested out the insertion operator to see if the things I am able to print
out the bits correctly.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

Professor Daly
Class Discord
https://www.cplusplus.com/

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

honestly the makefile had some issues, but was fixed during office hours back
on friday 1/28/22

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

 nothing else