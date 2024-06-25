/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Anson Cheang
Hours to complete assignment: 9 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The assignment for this part requires the user to make both a CelestialBody
and Universe class in order to print out the solar system, the movement is 
in the next part. I also scaled the size and implemented a friend function in
which I created a input >> operator. 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

The Unique Pointers, and the Vectors for storing it, since the unique pointers
allows it to be able to store earch planet only once, and the vector allowed for
the unique pointers to be stored and thus allowing it to print it all at once.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

I did use a smart pointer, which is the unique pointer, mostly just to make
a pointer for a CelestialBody object, and have it be stored in the vector a lot
easier than a lot of other things. The smart pointer I used it called a unique
pointer in which I can only store one copy of each item, making each of them 
unique, but since they are pointers they can only point to 1 object, hence the vector
needed to store each pointer. I also added a background.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

class discord
professor Daly

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

figuring out what each number on the pdf represents, and what their used fror
figured it out on friday 2/11/22

something wasn't running, but that was because I didn't clear the run time, nor
did I clear anything actually, fixed on 2/14/22

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

The Size of the window is 700 by 700, and as such the scale is based on 
that and the overall universe