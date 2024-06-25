/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Anson Cheang

Hours to complete assignment: 10 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

So this assignment has us make essentially a text scrambler using Markov model
which is mostly done, I just need to get through testing it, and making sure it works
which it doesnt so I am planning on working on it through the grace period tomorrow
or for the project redo.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

I used a nested map, as the pdf suggested I do, which make it easy to make
to access the amount of kgram assigned to those kgram, I think I used a nested 
map was because there was a pdf attached to this assignment that uses a nested map

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

not much just a bunch of iterators to go through the map, and nested maps
and the maps are of string and map, which is of char and int, made 
using pairs

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

No I didnt make it through the entire thing successfully, again planning
on finishing the rest tomorrow during grace period or during project redo,
the thing left to do is the << operator overload and the main.cpp, the 
RandWriter works, since it past the test.cpp test for it to work

/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

yes it does, it passed all of it, since when doing ./test with all
the BOOST_REQUIRE and it past all of it, and also tested for correct outputs
and the likes, and everything works

 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/

within the part where it told me to, when kmap != k, or order, whatever 
you call it, and when there is no such kgram. their mostly run time errors
which I use to match the reuirement listed within the pdf

 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/

I did not include any planning on finishing it for PSXB

/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/

no

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

James Daly
Class Discord
pdf attached to the assignment
Kevin S from discord helped with the pointer thing and char

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

everything, everything was a serious problem, the assignment was hard in
general, map of a map

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

This was submitted during the grace period, and is gonna be finished for the PSXB
assignment, although it would be nice if you could tell me what I did wrong
although that would be hard without a main, or TextWriter.cpp

TextWriter.cpp is empty dont bother checking

Makefile is set to test until TextWriter.cpp is finished
