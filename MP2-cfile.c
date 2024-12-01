#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern void vecDistance86(int n, double* x1, double* x2, double* y1, double* y2, double* z);

// C program to calculate the distance of coordinates in vectors
void vectorDistance(int n, double* x1, double* x2, double* y1, double* y2, double* z){
	for (int i = 0; i < n; i++){
		z[i] = sqrt(pow(x2[i]-x1[i]) + pow(y2[i]-y1[i]));
	}
}

//main function to call 86 and C kernels
int main(){
	int n = 4; //set this to the vector size n you want
	double x1[] = {1.5, 4.0, 3.5, 2.0};
    double x2[] = {3.0, 2.5, 2.5, 1.0};
    double y1[] = {4.0, 3.0, 3.5, 3.0};
    double y2[] = {2.0, 2.5, 1.0, 1.5};
	double* z = (double*)malloc(n*sizeof(double));
	
	//Time this function
	vectorDistance(n, x1, x2, y1, y2, z);
	
	//Print results and time
	printf("Results:\n");
    for (int i = 0; i < n; i++) {
        printf("%.8f ", z[i]);
    }
	
	
	//Time this function
	vecDistance86(n, x1, x2, y1, y2, z);
	
	//Print results and time
	printf("Results:\n");
    for (int i = 0; i < n; i++) {
        printf("%.8f ", z[i]);
    }
	
	
	return 0;
}
