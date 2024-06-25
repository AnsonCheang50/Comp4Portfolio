/**********************************************************************
 *  ps3-readme 
 *  Recursive Graphics (Triangle Fractal)                       
 **********************************************************************/

Your name: Anson Cheang

Hours to complete assignment: 15 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The assignment requires us to use recursive to draw out a triangle surrounded
by smaller triangle. it is essentially a sierpenski triangle but reversed, so rather
than the smaller triangle on the inside the smaller triangle is on the outside instead
making a weird triangle design. Overall I used curvex shape to design my triangle
and positioned each triangle to its proper position in order for them to be drawn.
I also changed the color, so top left is green, top right is red, and bottom is blue.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

the recursive function is a key algorithms, since it was needed to design
the whole triangle shape and design, and also made it so it only repeat as
needed without making it so that you need some repeated code over and over again
of course the recursive is called 3 times per function if it pass the if statement
check since each point of the triangle requires a triangle, and each of those 
triangle requires 3 triangle as well so yeah

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/

I implemented a curvex shape function essentially allowing me to place points
for the computer to draw lines to connecting them to make the shape.
As for the triangle, it's original position is in the lop left point, so 
position.x+size is where point 2 is, and point3.x = (point2.x + position.x)/2
then point3.y = sqrt(3)/2 * size, and that is how every point is found.
As for each triangle following, the length is divided by two, and I changed
the position to fit, so top left is moved left by size/2, and up by height, 
top right remains the same, bottom is moved left by length. Then make a triangle
for their position and length, as well as color, then call the recursive with the
new length, depth - 1, and each of the new triangle, so each time call 3 recursive
per triangle.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/

How to use recursive more effenciently, and how to use cpplint. 
I mostly learned cpplint, and how it works, how to use, essentially what
is needed for it etc.

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

Professor Daly
class discord
SFML website

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

blank output screen - fixed, it is just the processing speed, 10 was too 
much for my laptop to process quickly enough

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

Please note that the input for the function is 200 6 when i tried it, 
and that the first number is L then n. Also the more depth you want in
the output the longer it will run, since it is recursive a lot, so if it 
is greater than 6 (according to my laptop), is going to take a bit, just
a warning

Another note, the cpplint thing is in the makefile, so you dont have to worry about typing
that in.
