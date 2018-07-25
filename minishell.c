/*
 * RAJ KAPADIA 
 *
 *
 *
 * Description
 *
 * This program uses fork to create two children from a parent and uses 
 * the ls command to pipe it into the sort command that will sort the files 
 * in order.
 *
 *
 *I HEREBY CERTIFY THAT THIS PROGRAM IS MINE AND MINE ONLY - RAJ KAPADIA
 * 5704911
 *
 *
 * */





#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>





int main(){



	int pfds[2];
  	pipe(pfds);
	int c_pid;
	c_pid = fork();


	if(c_pid < 0){ //an error occurs
		printf("failed to fork");
		exit(-1);

	}else if(c_pid == 0){ //if parent 
		dup2(pfds[1],1);
		close(pfds[0]);
		execlp("/bin/ls", "ls", "-1", NULL);
		


	}else{
		dup2(pfds[0], 0);
		close(pfds[1]);
		execlp("sort", "sort", NULL);
		

	}

	
	return 0;




}

 
