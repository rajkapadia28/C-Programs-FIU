/* 
 * RAJ KAPADIA
 * 
 *I certify that this program is entirely my own work and none of it is the work
 * of any other person - RAJ KAPADIA*
 * 
 * This program takes in an input file and traverses through a line of words to determine which 
 * word is the longest and which is the shortest. Depending on the users request, either 
 * the longest word along with the count or the shortest word along with the count will 
 * be shown to the user.
 *
 *
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int debut =0;


int main(int argc, char **argv){

	 FILE* inFile = stdin;
	 extern char *optarg;
	 extern int optind;
	 int c, err = 0;
	 int lflag = 0, sflag = 0;
	 char *file; //file name
	 char lchar[200] = ""; //storing longest word
	 char schar[200] = ""; // storing shortest word
	 char temp [200]; // stores contents of file temporarily.
	 int lWordLength = 0; // count for longest word
	 int sWordLength = 99; //count for shortest word
	static char usage[] = "usage: countwords [-l] [-s] [filename] \n";
	
	char *tkspace; //token to catch white space in order to differentiate words
		
	while((c = getopt(argc, argv, "ls")) != -1)



		switch(c) { 
		

		case 'l': 
			lflag = 1;
			break;
		
		
		case 's':
			sflag = 1;
			break;

	
		case '?':   
			err = 1;
			break;

		}	
		

		 	

	
	

	inFile = fopen(argv[optind], "r");

	if(inFile == NULL){ //if file does not exist, the message below is printed.
	  	
		 printf("Could Not Open/Find File\n");	
		 exit(1);
	
	}else if(inFile != NULL){
		fgets(temp, sizeof(temp), inFile); //fgets is a function that reads a line and stores the string in a specific pointer. 
		tkspace = strtok(temp, " ");
	} //if file is found, tkspace acts as a identifier or delimiter. In this case a white space is recognized as the delimiter. 




		
		 
		
		

	while(tkspace && !isspace(*tkspace)){ //isspace is a function used to check whether the passed character is a white space. 

		
		if(lflag == 1){ //if the user wants to find the longest word, the output will be the word and the count.
						
			if(strlen(tkspace) > lWordLength){
			 
				 strcpy(lchar, tkspace); //the tkspace word is stored in lchar
		 	        lWordLength = strlen(tkspace);			
									

			}

		}

		
		if(sflag == 1){

			if(strlen(tkspace) < sWordLength){
			
				strcpy(schar, tkspace); //the tkspace word is stored in schar 
				sWordLength = strlen(tkspace);	 

			} //if the user wants to find the shortes string, then the output will be the shortest word and the count.		
		
		


		}


		

	   tkspace = strtok(NULL," ");
	}




	if(lflag == 1){

		printf("The longest word in the file is: %s\n It has a length of %d\n", lchar, lWordLength );

	}//output for the longest word.	
		
	if(sflag == 1){

		printf("The shortest word in the file is: %s\n It has a length of %d\n", schar, sWordLength);


	}	//output for the shortest word.


	
	return 0;

} //end



	 	

