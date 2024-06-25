/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Anson Cheang


Hours to complete assignment: 10 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

the assignment is to make a circularBuffer.cpp class, and test it within the
test.cpp, in order for them to work. the function for the class within the
circularBuffer is within the pdf, all we needed to do was implement it and boost 
test it.

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

I used deque. People said deque would be easier, Using vector 
has push back to insert it into the back, 
and [0] to get first value, and a delete to remove it. plus it also has pop_front
which allowed me to delete the front/first value.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

overall its not that much, its more deque using push_back to enqueue, 
delete for dequeue, and [] for both dequeue and peek. Other than that
it would be the error checking when throwing invalid_argument, or 
runtime_error.

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

yes I have completed the whole assignment

/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

yes it does, as it shows every error possible thrown correctly,
and every values return the correct values. afterall there is a lot
of boost require testing and stuff like that.

/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/

the time is O(1), and its size is O(1), I was using deque, and as such
it can easily remove the first value, look at the first value, and add
things into the back of the line if needs be

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

Professor Daly
class discord
SFML website

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

there wasn't any serious issues I have encountered

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

cpplint is within the makefile