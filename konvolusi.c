#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ROW 5
#define INPUT_COLUMN 5
#define FILTER_ROW 3
#define FILTER_COLUMN 3
#define MAX_STRING 200

// Deklarasi variabel
int inputMatrix[INPUT_ROW*INPUT_COLUMN];
float filterMatrix[FILTER_ROW*FILTER_COLUMN];
float outputMatrix[(INPUT_ROW-FILTER_ROW+1)*(INPUT_COLUMN-FILTER_COLUMN+1)];

void getMatrix(int *input, float *filter){
	FILE *filePointer ;
	 
	char filename[MAX_STRING];
	char buffer[MAX_STRING];
	char *token;
	int i = 0;

	printf("Masukkan nama file: ");
	scanf("%s", filename);
 
	filePointer = fopen(filename, "r") ;
	 
	if ( filePointer == NULL )
	{
		printf("File gagal dibuka.\n");
	}
	else
	{
		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(input+i) = atoi(token);
			token = strtok(NULL, ",");
			i++;
		}

		i = 0;

		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(filter+i) = atof(token);
			token = strtok(NULL, ",");
			i++;
		}

		fclose(filePointer);
	}

	return;
}

void convolution(int *input, float *filter, float *output)
{
	
	
}


void printMatrix(int *input, float *filter, float *output){
	printf("Matriks input: \n");
	for(int row = 0; row < INPUT_ROW; row++){
		for(int col = 0; col < INPUT_COLUMN; col++){
			printf("%d\t", *(input+row*(INPUT_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks filter: \n");
	for(int row = 0; row < FILTER_ROW; row++){
		for(int col = 0; col < FILTER_COLUMN; col++){
			printf("%.2f\t", *(filter+row*(FILTER_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks output: \n");
	for(int row = 0; row < INPUT_ROW-FILTER_ROW+1; row++){
		for(int col = 0; col < INPUT_COLUMN-FILTER_COLUMN+1; col++){
			printf("%.2f\t", *(output+row*(INPUT_COLUMN - FILTER_COLUMN + 1) + col));
		}
		printf("\n");
	}
}

int main()
{
	
	}
	getMatrix(int *input, float *filter);

}