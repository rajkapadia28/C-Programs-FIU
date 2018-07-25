/*
 *
 *Raj Kapadia 
 *
 *
 *Description: MINI CALCULATOR
 *This program takes the user input and makes calculations based on what the user has chosen. The 
 *user has a range of options from multiplication, division, subtraction, addition, and sqauring a 
 *number given by the user. Calculations are made using PEMDAS rule and the final answer is 
 *printed out by the end.
 *
 *
 * I HEREBY CERTIFY THAT THIS WORK IS MINE - RAJ KAPADIA 
 * PID: 5704911
 *
 * */

#include <stdio.h>
#include <stdlib.h>

 int debug = 0;

int main(int argc, char **argv)
{
	extern char *optarg;
	extern int optind;
	int c, err = 0; 
	int aflag = 0, dflag = 0, mflag = 0, sflag = 0, xflag = 0;
	//num values declared
	int anum = 0, dnum = 0, mnum = 0, snum = 0, xnum = 0; 
	float value = 0.0;//value is declared as float
	static char usage[] = "usage: %s [-a num] [-d num] [-m num] [-s num] [-x] value  \n";
	

	//this while loop is used to check the cases and change values of flag accordingly.
	while ((c = getopt(argc, argv, "a:d:m:s:x")) != -1)
		switch (c) {
		case 'a':
			aflag = 1;
			anum  = atoi (optarg);
			break;
		case 'd':
			dflag = 1;
			dnum  = atoi (optarg); //atoi
			break;
		case 'm':
			mflag = 1;	
			mnum = atoi (optarg); //atoi
			break;
		case 's':
			sflag = 1;
			snum = atoi (optarg); //atoi
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
	


	

	}
	
	value = atoi(argv[optind]);

			
	//checks if value entered by user is within the given boundary
	if((value < 1) || (value > 99)){
	
	printf("Error Message: The value %.0f is invalid \n %c",value, usage);
        exit(1);
	}
	//checks if mnum entered by user is within given boundary
	if((mnum < 0) || (mnum > 20)){
	
	printf("Error: The number %d is invalid\n", mnum);
	exit(1);
	}
	
	//checks if dnum entered by user is within given boundary	
	if((dnum < 0) || (dnum > 20)){

        printf("Error: The number %d is invalid\n");
        exit(1);
	}
	
	//checks if anum entered by user is within given boundary
	if((anum < 0) || (anum > 20)){

        printf("Error: The number %d is invalid\n");
        exit(1);
	 }
	
	//checks if snum entered by user is within given boundary
	if((snum < 0) || (snum > 20)){

        printf("Error: The number %d is invalid\n");
        exit(1);	
	}

	//checks is sflag is not 0. If not square  will take place
	if(xflag != 0 ){
	
	   value = value * value;
	   
	
	}
	
	//checks is mflag is not 0. If not multiplication will take place
	if(mflag !=0){

         value = value * mnum;
         
         }
	//checks is dflag is not 0. If not division will take place		
   	if(dflag !=0){

         value = (value / dnum);
         
	
	}

	//checks is anum is not 0. If not addition will take place
	if(aflag != 0){
	
	 value = value + anum;
	   		
	
	}

	//checks is snum is not 0. If not subtraction will take place
	if(snum !=0){
	  
   	  value = value - snum; 
	}
	//print final answer
	printf("%.2f\n", value);


}

