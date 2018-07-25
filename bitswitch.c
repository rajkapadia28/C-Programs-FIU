/*
 * Raj Kapadia 
 * 
 * Affirmation: this work is of my own and mine only - RAJ KAPADIA
 *
 * Program Description:
 * This program will ask the user to input a number from 1 to 1000 and will 
 * converted to a binary number. The user will also be asked to flip a bit of 
 * his/her choice. The new binary number will be outputted and the the 
 * binary number will converted to decimal.
 *
 * */



#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int) * 8

//This method is used for the power function, as math.h does not function
int power(int base, int exp){

	int result = 1;
	while(exp){

		result = result * base;
		exp--;	


	}
	return result; //returns the final answer




}//end power method


//this method converts the integer to binary and binary to integer.
void intToBin(unsigned k, int n){
	
	int arr[32];//declaring an array to hold the binary number.
	unsigned i; 
	int j = 31; 
	int sum = 0; //to convert back to decimal
	int sizeOfArr = 31; //fixed size.		
    	//for loop used to convert integer to binary
	
	for (i = 1 << 31; i > 0; i = i / 2){
       
		if(k & i){

			arr[j] = 1;
			j--;


		}else {
			arr[j] = 0;
			j--;
		}
	}// end for loop
	
	//Shows user the binary conversion	
	printf("For the decimal number %d, chosen by the user, binary number is below:\n ",k );


	// Prints the array with the binary conversion.
	for(j = 31; j >= 0; j--){

                printf("%d", arr[j]);
        }
	printf("\n");
	//Asks user which bit to flip.
	printf("This is the modified binary number after the flip \n");
	
	//For loop that looks at which bit the user has chosen. If the number is equal to that index, the number 
	//in that index will be flipped. 						
	for(j = 31; j >= 0; j--){
	
		if(j == n){
		
			if(arr[j] == 0){
				arr[j] = 1;
			}else{
				arr[j] = 0;
			}
		}

		printf("%d", arr[j]);
		
	}
	printf("\n");
	
	//The modified number is printed into decimal by using the power function and adding the numbers with all the indexes that have a 1.  
	printf("This is the modified decimal number after the flip:\n");
        for(j = 31; j >=0; j--){

            
            int index = sizeOfArr - j;
            if(arr[index] == 1){

              sum = sum + power(2,index);
		
            }
           
        }
	
	printf("%d\n",sum);
	sum = 0;	

}//end of inttobin method






int main(){

	char continueI = 'y';
	int userInput;
	int flipBit;
	

	while((continueI == 'Y') || (continueI == 'y')){

	printf("Choose a number between 1 and 1000:\n");	
	scanf("%d", &userInput);
	
	if((userInput < 1) || (userInput > 1000)){

		printf(" ERROR: The number is not between the specified range.\n");
		exit(0);
	}

	printf("What bit do you want to flip?\n");
	scanf("%d", &flipBit);		
	
	if(flipBit < 0 || flipBit > 31){
		
		printf("ERROR: Invalid Number\n");
		exit(0);
	}
	

	
	//itb(userInput, flipBit);
	intToBin(userInput, flipBit);	
	printf("\n");
	printf("Do you want to continue?\n");
	scanf(" %c", &continueI);	

	}




}//end main 








