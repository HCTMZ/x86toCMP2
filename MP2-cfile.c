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

void test(int n){
	double *x1 = (double*)malloc(n * sizeof(double));
    double *x2 = (double*)malloc(n * sizeof(double));
    double *y1 = (double*)malloc(n * sizeof(double));
    double *y2 = (double*)malloc(n * sizeof(double));
	double* z = (double*)malloc(n*sizeof(double));
	int i = 0;

	for (i = 0; i < n; i++) {
		x1[i] = 1.5;
		x2[i] = 3.0;
		y1[i] = 4.0;
		y2[i] = 2.0;
	}

    clock_t start, end;
	double total_time_c = 0.0, total_time_asm = 0.0;
	
	//Time this function
	for (i = 0; i < 30; i++) {
        start = clock();
        vectorDistance(n, x1, x2, y1, y2, z);
        end = clock();
        total_time_c += (double)(end - start) / CLOCKS_PER_SEC;
    }
	
	//Print results and time
	printf("Results:\n");
    for (i = 0; i < 10; i++) {
        printf("%.8f ", z[i]);
    }
    printf("\nC Kernel: n = %d, Average Time: %.8f ns\n", n, (total_time_c / 30)  * 1e9);
	
	printf("\n");
	
	//Time this function
	for (i = 0; i < 30; i++) {
        start = clock();
        asmVectorDistance(n, x1, x2, y1, y2, z);
        end = clock();
        total_time_asm += (double)(end - start) / CLOCKS_PER_SEC;
    }
	
	//Print results and time
	printf("Results:\n");
    for (i = 0; i < 10; i++) {
        printf("%.8f ", z[i]);
    }
    printf("\nASM Kernel: n = %d, Average Time: %.8f ns\n", n, (total_time_asm / 30) * 1e9);
	
}

int main(){
	printf("2^20: \n\n");
	test(pow(2,20));
	printf("2^24: \n\n");
	test(pow(2,24));
	printf("2^25: \n\n");
	test(pow(2,25));
	printf("2^26: \n\n");
	test(pow(2,26));
	printf("2^27: \n\n");
	test(pow(2,27));
	return 0;
}