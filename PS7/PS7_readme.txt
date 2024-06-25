/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Anson Cheang

Hours to complete assignment (optional): 10 hours

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/

Yes I believe I did, I have made a log.rpt that matches the original,
essentially when making the device5_intouch.log.rpt I compared it to
the bootonly rpt from the reports folder. I also removed the spaces at
the end of the 2 random lines since those seems to be there for some 
reason and bug me

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/

    string start_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    start_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}): \\(log.c.166\\) ";
    start_string += "server started";
    string end_string = "([0-9]{4})-([0-9]{2})-([0-9]{2}) ";
    end_string += "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:oejs.";
    end_string += "AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080";  //NOLINT

    regex start_regex(start_string);
    regex end_regex(end_string);

    only those two, with the start being what starts finds the beginning of 
    the boot, and the end being what finds the end of the boot. with
    start also checking if the previous boot ended correctly.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/

Essentially what I did was seperated it into smaller parts for me to work with
started off with finding where it begins and ends. Found out the starting process
matches one another and the ending process matched one another. then from there
checking if the boot ended correctly, in order to incorporate incomplete.
Then added in time using the date and time, along with having it be printed out.
Finally the line count, where its just counting the line as it goes through the file.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

Nick Daly
Matt
Regex slide in class notes
class discord
pdf
https://stackoverflow.com/questions/3789417/whats-the-difference-between-and-in-regular-expression-patterns

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

regex_match didn't work, replaced with regex search

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

the command ps7 is the executable
BTW the pdf has some inconsistency for example it says ps6, even though it shows
ps7