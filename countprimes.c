/*
 * Name: RAJ KAPADIA
 * 
 * Description: This program creats multiple processes to identify prime numbers
 * from a given range 
 *
 *
 *
 *
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>



#define N 50000
#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)



// The follwoing method finds the prime number from a given range
int primeNumberCount(int id, int num){

	int b;
	
	if(num < 2){ //if num is less than 2, return 0
		
		return 0;
	}
	
	//loop that goes through range
	for(b = 2; b < num; b++){

		if((num%b) == 0){
			return 0;
		}
	}

	printf("The current process is: %d and the prime number found is: %d\n", id, num);
	fflush(stdout);
	return 1;
}


int main(int argc, char *argv[]){


	/*Number of processes is defined through numProcesses. Each process is defined using the Process Rank */
	int i, processRank, numProcesses;
	int count;
	int k, index = 0;
	int primeCount; //final count of total prime numbers 
	double elapsed_time; //time for entire execution
	char hostname[1024];	
	/*Initializing MPI using the following line */
	MPI_Init(&argc, &argv);
	/* The rank of each Process is defined*/
	MPI_Comm_rank(MPI_COMM_WORLD, &processRank);
	/* The number of processes is defined*/ 
	MPI_Comm_size(MPI_COMM_WORLD, &numProcesses); 
	
	gethostname(hostname, 1023);
	printf("The MPI Rank is %d out of %d, on host %s\n", processRank, numProcesses, hostname );
	MPI_Barrier(MPI_COMM_WORLD);//creating a barrier where messages can be sent and recieved
	elapsed_time = -MPI_Wtime(); //time is displayed
	count = 0;
	
	for(k = processRank; k < N; k+=numProcesses){
		count += primeNumberCount( processRank, k);	

	}

	/*MPI_Reduce data present in all processes to 1 value and stores in the master process. As we require the 
 	 *number of prime numbers counted, we use the MPI_SUM operation (part of MPI_Reduce) as a reduced. This takes 
	 *the data from all processes, adds these values, and stores it into a buffer (if provided) in the master process
	 *or a process of choice.
	 */
	
	MPI_Reduce(&count,&primeCount,1,MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	elapsed_time += MPI_Wtime();
	if(!processRank){

		printf ("Execution time %8.6f\n", elapsed_time);
   		 fflush (stdout);

	}
	
	//printf("Process %d is done\n",processRank);
	//fflush(stdout);
	MPI_Finalize();
	
	if(!processRank){
	
		printf("There are %d numbers\n", primeCount);
		
	}
	
	return 0;
	


}
