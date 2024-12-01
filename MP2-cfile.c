#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// C program to calculate the distance of coordinates in vectors
void vectorDistance(int n, double* x1, double* x2, double* y1, double* y2, double* z){
	int i = 0;
	for (i = 0; i < n; i++){
		z[i] = sqrt(pow(x2[i]-x1[i], 2) + pow(y2[i]-y1[i], 2));
	}
}

extern void asmVectorDistance(int n, double* x1, double* x2, double* y1, double* y2, double* z);

//main function to call 86 and C kernels
int main(){
	int n = 4; //set this to the vector size n you want
	double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};
	double* z = (double*)malloc(n*sizeof(double));
	int i = 0;
	
	//Time this function
	vectorDistance(n, x1, x2, y1, y2, z);
	
	//Print results and time
	printf("Results:\n");
    for (i = 0; i < n; i++) {
        printf("%.8f ", z[i]);
    }
	
	printf("\n")
	
	//Time this function
	vectorDistance(n, x1, x2, y1, y2, z);
	
	//Print results and time
	printf("Results:\n");
    for (i = 0; i < n; i++) {
        printf("%.8f ", z[i]);
    }
	
	
	return 0;
}
