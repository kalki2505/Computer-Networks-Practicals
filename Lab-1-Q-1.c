/*
            AUTHOR: Kalki Bhavsar
            ROLL NUMBER: AU1841029
            EMAIL-ID: kalki.b@ahduni.edu.in
            COURSE: Computer Networks Lab
            SEMESTER: Monsoon 2020
            Degree: BTech ICT 2018-22
            FACUTLY: Professor Jitnedra Bhatia
          
                    >>>>> LAB ASSIGNMENT 1 <<<<<
 
        *******************QUESTION 1*****************
       
    Print a character n times where the character and n arguments passed as command­line arguments.
*/


#include <stdio.h>
#include <stdlib.h>

/*
    In the C/C++, unistd.h is a standard header file that provides access to the POSIX operating system API. 
    The Portable Operating SystemInterface (POSIX) is a family of standards specified by 
    the IEEE Computer Society for maintaining compatibility between operating systems.
    It is defined by the POSIX.1 standard, the base of the Single Unix Specification. 
    Ttherefore, this header file should be available in any conforming operating system/compiler 
    (all official versions of UNIX, including Mac OS X, Linux, etc.).

    It is mostly made largely of SYSTEM CALL WRAPPER FUNCTIONS such as:
        >>> fork        >>> pipe   >>> I/O primitives (read, write, close, etc.).

 */
#include <unistd.h>

//This function is to help users when they do not give input as per the required format,
// this function will help to know about that arguments they need to give.
void usage(void){
    printf("Usage:\n");
    printf(" ­n <repetitions>\n");
    printf(" ­d <char to dispaly>\n");
    exit (8);
}


int main (int argc, char *argv[]){

// Default value of num = 2 and the display character by default is '*'
    int n= 2;
    char display_character = '*';
    char c;
    
/*          getopt() function
    >>> The getopt() function is a builtin function in C.
    >>> It is used to parse command line arguments.
    >>> SYNTAX:
        getopt(int argc, char *const argv[], const char *optstring)

        >>  Its arguments argc and argv that are passed to the main() function on program invocation:
                argc: argument count
                argv: array

    >>> If getopt() is called repeatedly, it returns successively each of the option characters from each of the option elements.
        Hence this functions is generally called from inside of a loop’s conditional statement. 
        When, the loop terminates when the getopt() function returns -1. 
        A switch statement is then executed with the value returned by getopt() function.
        If there are extra arguments, one more loop is used to process those arguments that cannot be processed in the first loop.
    
    >>> The getopt() function returns different values:

            > If the option takes a value, that value is pointer to the external variable optarg.
            > ‘-1’ if there are no more options to process.
            > ‘?’ when there is an unrecognized option and it stores into external variable optopt.
            > If an option requires a value (such as -f in our example) and no value is given, getopt normally returns ?.
            > By placing a colon as the first character of the options string, getopt returns: instead of ? when no value is given.

            If an option was found successfully, then getopt() returns the characters from the options passed.  
            If all command-line options have been parsed, then getopt() returns -1.  
            If getopt() encounters an option character that was not in optstring, then '?' is returned. 
    */
    

    while(1){
        c = getopt(argc, argv, "n:d:");     // c can be n or d. In other cases, default exit is considered.
        if(c == -1){
            break;      //getopt() returns -1 when no more options are available
        }else{
              //printf("s = %c\n", c);
        }
    
        switch(c){
            // c can be n or d. In other cases, default exit is considered.
            case 'n':{
                n = atoi(optarg);     
                //optarg is a character array, we need to convert its value to int. 
                //So we use function atoi()
                break;
            }
            
            case 'd':{
                display_character = optarg[0];
                //optarg is a character array, we need only the first character
                //Fence optarg[0]
                break;
            }
            
            default:{
                //default: explain how to use this program and then, exit
                usage();
                //exit (1);
            }
        }
    }
    //Print the character disp, num times
    printf ("\n\tAttention User! The following %d lines will display the character \'%c\' (without quotes)\n",n, display_character);
    int i;
    for (i = 0; i < n; i++){
        printf ("\t\tLine %d: %c\n", (i+1), display_character);
    }
    return 0;
}
