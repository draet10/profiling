#include<stdlib.h>
#include<stdio.h>

#define MSIZE 2000

double matrix_a[MSIZE][MSIZE];
double matrix_b[MSIZE][MSIZE];
double matrix_r[MSIZE][MSIZE];

void initialize_matrix(){
	//printf("Initializing Matrices\n");
	int i,j;
	for(i=0;i<MSIZE;i++){
		for(j=0;j<MSIZE;j++){
			matrix_a[i][j]= (double) rand() / RAND_MAX; 
			matrix_b[i][j]= (double) rand() / RAND_MAX;
            //matrix_r[i][j] = 0.0; 
		}	
	}
	//printf("Intialized Matrices\n");

}

void multiply_matrix(){
	int i,j,k;
	//printf("Matrix multiplying\n Wait for 3-4 mins\n");

	for(i=0;i<MSIZE;i++){
		for(j=0;j<MSIZE;j++){
			double sum = 0.0; 
			for(k=0;k<MSIZE;k++)
				sum += matrix_a[i][k]*matrix_b[k][j];				
			matrix_r[i][j] = sum;
		}
	}
	//printf("\nMatrix multiplied\n");
}

void print_result(){
	int i,j;
	for(i=0;i<MSIZE;i++){
		for(j=0;j<MSIZE;j++){
			//printf("%lf \t", matrix_r[i][j]);
		}	
		//printf("\n");
	}
}

int main(){
	//printf("Testing matrix multiplication unoptimized \n");
	initialize_matrix();
	//printf("Starting the multiplication of Matrix A  & B: -  \n");
	multiply_matrix();
	//print_result();
}
