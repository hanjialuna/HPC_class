/* 
	array demonstration from David Chopp
	Creating multi-dimensional arrays
	
	Inputs: two integers for the dimensions of the array
	Outputs: The contents of the array in order
	
	Editing history: 
	04/01/2016
*/

#include <stdio.h>
#include <stdlib.h> // need this for atoi

/*
This prgram displays the size requirements in bytes
Inputs: argc should be 3, argv[1] will contain the number of rows,
	argv[2] will contain the number of columns
Outputs: Prints the contents of the array
*/

int main (int argc, char* argv[])
{
	int numberOfRows = atoi(argv[1]); 
	int numberOfCols = atoi(argv[2]);
	int numberOfLayers = atoi(argv[3]);
	int (*array)[numberOfCols] = malloc(sizeof *array * numberOfRows);
	int* pointer = &(array[0][0]);
	
	printf("Example of double array storage:\n");
	for (int i=0; i<numberOfRows; ++i) {
		for (int j=0; j<numberOfCols; ++j){
			array[i][j] = 100 *i + j;
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);
		}
	}
	
	for (int i=0; i<numberOfRows*numberOfCols; ++i){
		printf("pointer[%d] = %d\n", i, pointer[i]);
	}
	
	free(array); 
	
	printf("\nExample of triple array storage:\n");
	int (*array3D)[numberOfCols][numberOfLayers] = malloc(sizeof *array3D * numberOfRows);
	
	int* pointer3D = &(array3D[0][0][0]);
	
	for (int i=0; i<numberOfRows; ++i){
		for (int j=0; j<numberOfCols; ++j){
			for (int k=0; k<numberOfLayers; ++k){
				array3D[i][j][k] = 10000*i + 100*j + k;
				printf("array3D[%d][%d][%d] = %d\n", i, j, k, array3D[i][j][k]);
			}
		}
	}
	
	for (int i=0; i<numberOfRows*numberOfCols*numberOfLayers; ++i){
		printf("pointer3D[%d] = %d\n", i, pointer3D[i]);
	}
	free(array3D);
	
	return 0;
}