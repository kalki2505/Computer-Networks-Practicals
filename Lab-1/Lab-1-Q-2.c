/*
			AUTHOR: Kalki Bhavsar
			ROLL NUMBER: AU1841029
			EMAIL-ID: kalki.b@ahduni.edu.in
			COURSE: Computer Networks Lab
			SEMESTER: Monsoon 2020
			Degree: BTech ICT 2018-22
			FACUTLY: Professor Jitnedra Bhatia

					>>>>> LAB ASSIGNMENT 1 <<<<<

		*******************QUESTION 2*****************
	Modify the code so that a user can supply the filename from command line
	using ­i filename switch. Further, if the user does not supply the filename, your
	program should attempt to read sample.txt by default.

	➔ Finally, modify the code to copy an input file to an output file. The user may
	supply the output filename using ­o outfile switch, else output the copy to
	sample_out.txt by default.
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
#include <string.h>
int main(int argc,char *argv[]){
	/* Pointer to the source file */
	//Minimum arguments = source file + -i + input file + -o + outputfile = 5. If total arguments are > 5 then input format is not correct. 
	if(argc > 5){
		printf("The input format is not correct. More than one files in the input. Total files = %d\n", argc);
		exit(EXIT_FAILURE);
	}else{
		FILE *src;		// pointer to source file
		FILE *dst;		// pointer to destination file
		
		//Default source and destination files
		char src_file[] = "Sample.txt";		// source file name
		char dst_file[] = "Sample-out.txt";	// destination file name

		src = fopen (src_file, "r");
    	if(src == NULL){
        	printf("Default Input File \"Sample.txt\" not found. Exiting.\n");
			exit(EXIT_FAILURE);
        }
    	dst = fopen (dst_file, "w+");		


		int c;
		while(1){
	        c = getopt(argc, argv, "i:o:");	// c can be i or o. In other cases, default exit is considered.		
	        if(c == -1){
	            break;			//getopt() returns -1 when no more options are available
	        }else{
	              //printf("s = %d\n", c);
	        }
	    
	        switch(c){
	        	// c can be i or o. In other cases, default file is considered.
	            case 'i':{
	            	//Opening the source file in reading mode
	                src = fopen (optarg, "r");
	                if(src == NULL){
	                	printf("Input File \"%s\" not found. Exiting.\n", optarg);
						exit(EXIT_FAILURE);
	                }
	                //src_file = optarg;
	                //Copying the source file name from optarg to src_file
	                strcpy(src_file, optarg);
	                break;
	            }
	            
	            case 'o':{
	               dst = fopen (optarg, "w+");	
	               //Open destination file in writing mode. If the file does not exist, create a new one.	        
	                //dst_file = optarg;
	                //Copying the destination file name from optarg to dst_file
	                strcpy(dst_file, optarg);
	                break;
	            }
	            
	            default:{
	            	//By default, input file is "Sample.txt" and output file is "Sample-out.txt"	            
	            	//Open destination file in writing mode. If the file does not exist, create a new one.	           
	            }
	         
	        }
	    }
	    //SIMPLE CODE TO COPY CONTENTS OF ONE FILE TO ANOTHER FILE
	    //printf("%s %s\n", src_file, dst_file);
		int ch = fgetc(src); // read character ch from source file
		//printf("%d\n", ch);
	    while (ch != EOF){ 	//read ch until end of file
	        fputc(ch, dst); // write character ch to destination file
	        ch = fgetc(src); 
	        //printf("%d\n", ch);
	    } 
	    //closing the file pointers
	    fclose(src);
	    fclose(dst);
	    //output message
	    printf("\n\t\tMESSAGE: Entire text from file \"%s\" is now copied to file \"%s\" successfully.\n", src_file, dst_file);
	}
	return 0;
}
	