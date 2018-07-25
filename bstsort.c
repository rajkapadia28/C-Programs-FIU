/*
 *Name: Raj Kapadia	
 *
 *
 *Certification: I hereby certify that this is my work and only mine- RAJ KAPADIA
 *
 *Program Description:
 *The following program uses a linked list structure and reads from a file to add 
 *each line into a node. Each node is then compared using an inorder traversal and is 
 *used to output an alphabetical order of sentences. The user has the option of giving an 
 *output file, an input file, or using the command line to input his/her own words.
 *
 */






#include <stdio.h>
#include <stdlib.h>
#include <string.h>








	struct node{ //initiating structure of linked list
	
		char  *key;
		struct node *left; //left node
		struct node *right;//right node
		int countKey; //keeps count of duplicate
		int numNodes;// keeps count of total nodes
 	};//end struct	
	typedef struct node treeNodeS; 	//name for treenode structure
	typedef treeNodeS *tNode; //pointer for tree node structure

	struct node *newNode(char *value){//new node created using the structure

		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->key = value;
		temp-> left = NULL;
		temp-> right = NULL;
		temp->countKey++;
		temp->numNodes++;
		return temp;

	};//endNewNode
	



	
	void  insertNode(tNode *treeNode, char *key, int cflag){//insert method used to add nodes to BST

		if(*treeNode == NULL){ //checks if tree is empty

			*treeNode = malloc(sizeof(struct node));
		
			if(*treeNode != NULL){// creates new node

				//newNode(key);
				char *tempS = (char *)malloc(sizeof(key));
				(*treeNode)->key = tempS;
				(*treeNode)->left = NULL;
				(*treeNode)->right = NULL;
				(*treeNode)->numNodes++;
			}
			
			

		}else{
			
			char *input = (*treeNode)->key;
			if(cflag == 1){
				if(stringCompare(key, input) <0){
					insertNode(&(*treeNode)->left,key, 0);
					(*treeNode)->numNodes++;
					(*treeNode)->countKey++;
									
				 }else if(stringCompare(key, input) > 0){
				
					insertNode(&(*treeNode)->right, key, 0);
					(*treeNode)->numNodes++;
					(*treeNode)->countKey++;


				}
				


			}else {
				
				if(noCaseStringCompare(key, input) < 0){
			
			 		insertNode(&(*treeNode)->left, key, 0);
					(*treeNode)->numNodes++;
					(*treeNode)->countKey++;	
		


				}else if(noCaseStringCompare(key, input)> 0){

					insertNode(&(*treeNode)->right, key, 0);
					(*treeNode)->numNodes++;
					(*treeNode)->countKey++;

				}	
			
		
			}


		}
	
	}//end of insertNode





	int noCaseStringCompare(char *key, char *input){//comparison between nodes that is not case sensitive 

		int cflag = 0;
		int i = 0;
		int keyChar = 0;
		int inputChar = 0;	

		while(key[keyChar] != '\0'){
			
			key[keyChar] = tolower(key[keyChar]);
			keyChar++;
			

		}
		
		while(input[inputChar] != '\0'){
		
			input[inputChar] = tolower(input[inputChar]);
			inputChar++;	
		}
	
		
		while(key[i] == input[i] && key[i] != '\0' && input[i] != '\0'){
			

			i++;
					

		}
		if(key[i] < input [i]){
			
			cflag = -1;



		}

		if(key[i] > input[i]){
		
			cflag = 1;
		
		}

		return cflag;
	}		



	int stringCompare(char *key, char *input){ //comparing strings that are case sensitive

		
		int i =0;
		int cflag = 0;
		
		while(key[i] == input[i] && key[i] != '\0' && input[i] != '\0'){
		
			i++;

		}

		if(key[i] < input[i]){
			
			cflag = -1;	

		}

		if(key[i] > input[i]){

			cflag = 1;

		}

		return cflag;



	}// end of stringCOmpare 

	void inOrder(tNode treeNode, FILE* out_file_name ){ //adding nodes to given outfile by inorder traversal

		if(treeNode != NULL){
			

			inOrder(treeNode->right, out_file_name);
			fprintf(out_file_name, "$s", treeNode->key);
			inOrder(treeNode->left, out_file_name);

		}

	}




	void freeNodes(tNode treeNode){ //recursive method that frees nodes

		if(treeNode != NULL){

			freeNodes(treeNode->right);
			freeNodes(treeNode->left);
			freeNodes(treeNode);
			treeNode = NULL;
			
		
		
		
		}

	}










int main(int argc, char **argv){ //Main 

		
		tNode rootTree= NULL; //Declaring Tree
		extern char *optarg;
		extern int optind;
		int c, err = 0;
		int cflag = 0;
		int oflag = 0;
		FILE *outfile = stdout;	
		FILE *infile;
		char tf[100];
		char temp[100];
		static char usage[] = "usage: $s [-c caseSensitive] [-o output_file] [input_file] \n";
		



		while((c = getopt(argc, argv, "co:")) != -1){





			switch(c){
			
			case 'c':
					
				cflag = 1;
				break;
			
			case 'o':
			
				oflag = 1;
				outfile = fopen(optarg, "w");
				break; 



			case '?': 
			 	err = 1;
			 	break;		

			}

		}//while loop end

	

	if((optind + 1) > argc ){ //If user prompts command line, the following will take place. User will have a choice to end inputting by entering.
		FILE *temp;
		temp = fopen("tempFile", "w");
		printf("Enter the input here:\n");
		fgets(tf, 100, stdin);
		while(strcmp(tf, "\n")!= 0){
			fprintf(temp, tf);
			fgets(tf,100,stdin);
				
	
		}
		printf("Out of loop\n");
		//infile = stdin;
	        
	
	fclose(temp);
	}
		
	else {
		infile = fopen(argv[optind], "r");


	}
	if(!infile){
		printf("Error: %s\n", usage);
		

	}

	while(fgets(temp, 100, infile) != NULL){

		if(oflag != 0){
			fprintf(outfile, "%s\n", temp);
		
		}else{
			printf("%s\n", temp);

		}
		


	}//end of while loop
	

	inOrder(rootTree, outfile);//Inorder traversal
	freeNodes(rootTree);	//Freeing nodes
	fclose(infile); //closing input file
	fclose(outfile);//closing output file










}//end of main









