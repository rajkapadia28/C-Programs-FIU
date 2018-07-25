/*
 * RAJ KAPADIA 
 * 5704911
 *
 *
 * Description: 
 *
 * THe program below rotates, scales, and flips images according to users preference. 
 * The user is allowed to rotate the image in either clockwise or counter clockwise directio
 * Depending on the user's input in terms of the degree's the user choose (should be a 
 * factor of 90), the image will be rotated accordingly.
 *
 *
 * I HEREBY CERTIFY THAT THIS WORK IS OF MNE AND MINE ONLY - RAJ KAPADIA
 * 5704911
 *
 *
 *
 *
 *
 * */








#include <stdlib.h>
#include "bmplib.h"
#include <getopt.h>
#include <stdio.h>
/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * scale    - the multiplier applied to EACH OF the rows and columns, e.g.
 *           if scale=2, then 2* rows and 2*cols
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */
int enlarge(PIXEL* original, int rows, int cols, int scale, 
	    PIXEL** new, int* newrows, int* newcols) 
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */

	int row;
	int col;
	
	if((rows <= 0) ||(cols <= 0)){

		return -1;
	}

		(*newrows) = (scale * rows);
		(*newcols) = (scale * cols);
		//memory received from malloc of type PIXEL. Memory required of size PIXEL multiplied by the number of rows and columns. 
		*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));
		
		for(row = 0; row<(*newrows);row++){
			for(col = 0; col<(*newcols); col++){

	(*new)[row * (*newcols) + col] = original[(row * rows / (*newrows))  * cols + col * cols / (*newcols)];	
		
			}//end of inner for loop
	
		}//end of outer for loop

		
		
		
			
		
  return 0;
}

/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read 
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 * 
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation, 
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
int rotate(PIXEL* original, int rows, int cols, int rotation,
	   PIXEL** new, int* newrows, int* newcols)
{

	int row;
	int col;
	 
	//rotations occuring according to degree selected. Conditions created accordingly.
	if((rotation % 360) == 0){

		*newrows = rows;
		*newcols = cols;
		*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));	
	
		for(row = 0; row < rows; row++){
			for(col = 0; col < cols; col++){
				PIXEL* o = original + row*cols + col;
				PIXEL* n = (*new) + row*cols + col;
				*n = *o;
			}
		}
	}else if((rotation > 0 && rotation % 270 == 0) || (rotation < 0 && rotation % 90 == 0		 && rotation % 180 != 0 && rotation % 270 != 0)){

		*newrows = cols;
		*newcols = rows;
		*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));

		for (row=0; row < rows; row++){
			for (col=0; col < cols; col++) {
				PIXEL* o = original + row*cols + col;
				PIXEL* n = (*new) + col*rows + (rows-row-1);
				//PIXEL* n = (*new) + (cols-col-1)*rows + row;
				*n = *o;
			}
		}

	}else if((rotation > 0 && rotation % 180 == 0) || (rotation < 0 && rotation % 180 ==		 0)){

			*newrows = rows;
			*newcols = cols;
			*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));

			for (row=0; row < rows; row++){
				for (col=0; col < cols; col++) {
					PIXEL* o = original + row*cols + col;
					PIXEL* n = (*new) + (rows-row)*cols - (col+1);
					*n = *o;
				}
			}
	
	}else if((rotation > 0 && rotation % 90 == 0) || (rotation < 0 && rotation % 270 == 0		)){
	
		*newrows = cols;
		*newcols = rows;
		*new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));

		for (row=0; row < rows; row++){
			for (col=0; col < cols; col++) {
				PIXEL* o = original + row*cols + col;
				PIXEL* n = (*new) + (cols-col-1)*rows + row;
				//PIXEL* n = (*new) + col*rows + (rows-row-1);
				*n = *o;
			}
		}
	
	}

		
 
  return 0;
}

/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile(). 
 * 
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
int flip (PIXEL *original, PIXEL **new, int rows, int cols) 
{
  int row, col;

  if ((rows <= 0) || (cols <= 0)) return -1;

  *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

  for (row=0; row < rows; row++)
    for (col=0; col < cols; col++) {
      PIXEL* o = original + row*cols + col;
      PIXEL* n = (*new) + row*cols + (cols-1-col);
      *n = *o;
    }

  return 0;
}

int main(int argc, char **argv)
{

  int r, c;
  int newr, newc; //new rows and columns 
  PIXEL *b, *nb;
  char* infile = NULL;
  char*  outfile = NULL;
 // int tmp, scale_value, rotation_value;
  extern char *optarg;
  extern int optind;
  int sflag, rflag, oflag,fpflag;
  sflag = 0;
  rflag = 0;
  oflag = 0;
  fpflag = 0;	
  int snum, rnum;
  snum = 0;
  rnum = 0;
  static char usage[] = "usage: %  bmptool[-s scale | -r degree |-f] [-o output_file][input_file]\n";
  c = 0;
  int error = 0;
	//while statement to set flags according to user preference. 
	while((c = getopt(argc, argv,"s:r:fo:")) != -1)
	
		switch(c){
			case 's':
				sflag = 1;
				snum = atoi(optarg);
				break;
			case 'r':
				rflag = 1;
				rnum = atoi(optarg);
				break;
			
			case 'f':
				fpflag = 1;
				break;
		
			case 'o':
				oflag = 1;
				outfile =optarg;
				break;
			case '?':
				error = 1;
					
				printf("%s", usage);
				return 1;
					
		
		}
	

 // printf("%d\n",sflag);
 // printf("%d\n",rflag);
 // printf("%d\n",fpflag);
 // printf("%d\n",oflag);

 // printf("%s\n",usage);
  if(argv[optind] != NULL){
	infile = argv[optind];
  }else if(optind < argc){
 
  	printf("%s", usage);
	exit(-1);

  }
	
  readFile(infile, &r, &c, &b);
 
 //if user wants to scale, sflag =1 and the scale  method is called.
  if(sflag != 0){
	enlarge(b, r, c, snum, &nb, &newr, &newc);  
	r = newr;
	c = newc;
	b = nb;
	
  }
   //if user wants to rotate, rflag =1 and the rotate method is called.
  if(rflag != 0){
	rotate(b, r, c, rnum, &nb, &newr, &newc);
        r = newr;
        c = newc;
        b = nb; 

  }
  //if user wants to flip, fpflag =1 and the flip method is called.
  if(fpflag != 0){
	flip(b, &nb, r, c);
	b = nb;
 	 
  }

 

  writeFile(outfile, r, c, nb);
    
  free(b);
 //free(nb);
  return 0;
}
