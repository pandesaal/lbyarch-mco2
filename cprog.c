#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRMAX 1073741824
#define SANITY 1

extern float sdotComp(float *array1, float *array2, int size);

float* initArr() {
	float *arr = (float *)malloc(sizeof(float) * ARRMAX);
	if (arr == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    
    for (int i = 0; i < ARRMAX; i++){
    	arr[i] = 2;
	}
	
	return arr;
}

void sanityCheck(float *array1, float *array2, int size){
	float res = 0;
	for (int i = 0; i < size; i++){
		res += array1[i]*array2[i];
	}
	
	printf("Dot product (C check):	 %f\n", res);
}

int main() {
	
	float *arr = initArr();
	
	int n = 0;
	float result = 0;
	
	printf("Enter length of vector (int): ");
	scanf("%d", &n);
	
	result = sdotComp(arr, arr, n);
	printf("Dot product (ASM check): %f\n", result);
	if (SANITY) sanityCheck(arr, arr, n);
	
	free(arr);
	return 0;
}
