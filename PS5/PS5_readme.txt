/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Anson Cheang

(Partnering is optional. See the guidelines on the assignments page.)
Partner's name: Andy Nguyen

Hours to complete assignment (optional): 15 hours

Which partner is submitting the program files?

Both of us, we are labling each other as partners

/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/

essentially follow the equation that was given in the dynamic programming class
notes, which leads to errors since it was going backward, was then changed to 
make it go forward, but still follow the same formatting, mainly because the extra
space was at the back instead of the front. Then from then was output changes until it
matches the one in the pdf, so overall follow the pdf method for the most part
and then change for output matching.

/**********************************************************************
 * You are required to create one additional test case by hand. 
 * It should be constructed in such a way that you know the correct 
 * output before running your program on it, and it should be a 
 * "corner case" that helps check if your program handles all special 
 * situations correctly. Please list:
 * - a copy of the test case input
 * - the expected test case output
 * - whether your program ran correctly on it or not
 * - optionally, any other remarks
 **********************************************************************/
Input: essentially the endgaps7.txt

atattat
tattata

Expected output:

Edit Distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened: printed it out correctly

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2GB and 4GB. If your machine has 512MB or less, use a cluster
 *  machine for this readme (see the checklist for instructions).
 **********************************************************************/

8GB of memory to be used

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 4
largest N = 125

b is ints, and as such has to be 4 bytes, a is an int from what I am assuming
rounding down

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *  For help on how to do timing, see the checklist (e.g. -Xprof).
 *  If you get an OutOfMemoryError, see the checklist about -Xmx.
 *  If you get "Could not reserve enough space for object heap" or the timing
 *  of these tests takes too long for the last few test cases (N=20000 or higher), 
 *   note this, and skip filling out those rows of the table.
 **********************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt           118         0.647       
ecoli5000.txt           160         2.549
ecoli10000.txt          223         10.5614
ecoli20000.txt          3135        44.0558
ecoli50000.txt          killed
ecoli100000.txt         killed


/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 4
b = 2
largest N = 146

rounding down. b has to be two since everytime N doubles the time quadruples

/**********************************************************************
 *  If you worked with a partner, do you have any remarks on the pair
 *  programming method? E.g., how many times did you switch, what are
 *  the tradeoffs of driving vs. navigating, etc.
 **********************************************************************/

well we switched a couple of times, if anything it can show what issues
is caused by the other person, as if looking at it from a new angle. 
Plus driving is writing code, and navigating is essentially telling the 
other what should be there.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs, preceptors,
 *  classmates, past COS 126 students, or anyone else.
 **********************************************************************/

James Daly
Class Discord
Dynamic Programming class notes
PS5 pdf

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

out of bound and outputting errors, forgot () in the optDistance
apparently ++ instead of --, and going forward works better than going
backward

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

the program killed itself at ecoli50000.txt

Too afraid to test out 100000 my laptop fan
was running like crazy at 28284 - was legit worried about my laptop blowing up

there is a cut off point on linux, so I added a cout to see edit distance after
alighnment was printed out, just so I can see the edit distance (its commented out).
