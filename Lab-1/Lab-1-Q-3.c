/*
			AUTHOR: Kalki Bhavsar
			ROLL NUMBER: AU1841029
			EMAIL-ID: kalki.b@ahduni.edu.in
			COURSE: Computer Networks Lab
			SEMESTER: Monsoon 2020
			Degree: BTech ICT 2018-22
			FACUTLY: Professor Jitnedra Bhatia
			
					>>>>> LAB ASSIGNMENT 1 <<<<<

		*******************QUESTION 3*****************
	Write a program that when executed creates two child processes using fork() system
	call where one child process prints date and the other does the tracing of route to
	google dns server. Further, all three processes print their PID and identify themselves
	as parent, child 1 and child 2 prior to printing anything else.

	Approach:
	In the parent process, we first create child1 process using fork.
	That fork will create one more new child process - child process 1 - to print current date and time. 
	In this new chile process (chile process 1), we will add one more fork.
	This fork will create a new child process - child process 2 - to trace the route to google dns server. 

	To identify whether parent or child process, we will use codes that fork returns.
	We will use inbuilt function to print PID of the current process.
*/

#include <stdio.h>
#include <stdlib.h>


/*			time.h
	The time.h header file contains definitions of functions to get and manipulate date and time information.

	Datatypes defined in time.h:
		1. 	clock_t: 	clock_t represents the date as integer which is a part of the calendar time.
		2.	time_t: 	time_t represents the clock time as integer which is a part of the calendar time.
		3. 	struct tm: 	struct tm holds the date and time which contains:
	
						struct tm { 			  
						    int tm_sec; 	// seconds,  range 0 to 59
						    int tm_min; 	// minutes, range 0 to 59
						    int tm_hour; 	// hours, range 0 to 23 			
						    int tm_mday; 	// day of the month, range 1 to 31 			  			   
						    int tm_mon; 	// month, range 0 to 11 			  			 
						    int tm_year; 	// The number of years since 1900 
							int tm_wday;  	// day of the week, range 0 to 6 
						    int tm_yday; 	// day in the year, range 0 to 365 			
						    int tm_isdst; 	// daylight saving time 
						}

	Pre-defined functions in time.h:
		>>> 	time() -> returns the calendar-time equivalent using data-type time_t
		>>>		localtime() ->  returns the local time of the user computer
		>>>		strftime()-> formats the string returned by other time functions using different format specifiers
*/
#include <time.h>

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


/*The header file which is required to include in the program to use pid_t is sys/types.h*/
#include <sys/types.h>

int main(int argc, char *argv[])
{
	/*
		pid_t data type stands for process identification
		It is used to represent process ids. 
		Hence this data type is used to declare a variable that is going to be deal with
		the process ids. 
		The type of pid_t data is a signed integer type (signed int).


		There are basically two functions, which returns the process ids i.e 
		return type of those functions is pid_t.

			1. getpid() – returns the process id of the calling process
				SYNTAX: pid_t getpid()

			2. getppid() – returns the parent process id in which the function is calling
				SYNTAX: pid_t getppid()
	*/
    pid_t child1, child2, pid;	// variable that stores the process id's of child process A and B.



/*				fork()
		On calling fork(), a new process is created, which is called the child process.
		The process that makes the fork() call is called as parent process.
		The new child process runs concurrently along with the parent process.
			"Baap - beta ek saath kaam karege! --> analogy to make it more clear
		After a new child process is created, both processes will execute the next instruction
		The parent process will process the instructions following the fork() system call.
		The child process will be the parent process only that will start from the begining.

		PARAMETER: void
		RETURN TYPE: int
		RETURN VALUES: int
			Negative value: If the creation of the child process was unsuccessful
			Zero value: If it returns to the new child process.
			Positive value: If it returned to parent or caller.
							The return alue contains process-ID of the new child process.

*/
    child1 = fork();

    if(child1 == 0){
        pid = (long)getpid();
        //Declaring variables
        char current_time[128];  
        time_t time_;
        struct tm*  present_time;


        time_ = time(NULL);	//clock time
        present_time = localtime(&time_); // local time of the user computer
        printf("\n\nChild Process 1 is running whose process ID is %ld\n", (long)getpid());
        strftime(current_time, 128, "%d-%b-%Y %H:%M:%S", present_time);
        printf("The current date and time is %s\n", current_time);
    } 


    else { 
        child2 = fork();
        if(child2 == 0) {
            pid = (long)getpid();
            printf("\n\nChild Process 2 is running whose process ID is %ld\n", (long)getpid());	
            printf("The following lines shows the tracing of route to Google DNS Server\n");	
			
/*			The C library function: system()
		DECLARATION SYNTAX:int system(const char *command)
		PARAMETERS: a C string that contains the name of the varible that stores the command to be executed
		RETURN VALUE: On error, he value -1 is returned or else the return status of the command is returned.
		USAGE: The function passes the command name or program name specified by command
				to the host environment to be executed by the command processor 
				and returns after the command has been completed.
*/

/*
			Traceroute command
		When packets are sent across the internet, they must hop from network to network. 
		The traceroute command traces the route that packets takes to reach the host. 
		It will show you how many hops it takes to reach the host and 
		how long it took between each hop. 
		This allows you to diagnose potential networking bottlenecks.
		The example below shows the traceroute command output from your local PC to Google server. 
*/

            system("traceroute to www.google.com");		
        } else {
            pid = (long)getpid();
            printf("\n\nParent Process is running whose process ID is %ld\n", (long)getpid());

        }    
    }

    return 0;
}
