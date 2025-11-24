#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPEAT 30
#define ARRMAX20 1048576
#define ARRMAX24 16777216
#define ARRMAX30 1073741824
#define SANITY 1
#define RUNWITHASM 1

extern float sdotComp(float *array1, float *array2, int size);

float* initArr() {
	float *arr = (float *)malloc(sizeof(float) * ARRMAX30);
	if (arr == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    
    for (int i = 0; i < ARRMAX30; i++){
    	arr[i] = 1.0;
	}
	
	return arr;
}

float kernelCompC(float *array1, float *array2, int size){
	float res = 0;
	for (int i = 0; i < size; i++){
		res += array1[i]*array2[i];
	}
	
	return res;
}

void run(float* arr, int n){
	if (SANITY) {
		float resC = kernelCompC(arr, arr, n);
		printf("Dot product (C check):	 %f\n", resC);
		
		if (RUNWITHASM){
			float resASM = sdotComp(arr, arr, n);
			printf("Dot product (ASM check): %f\n", resASM);
		}
	}
	
	time_t startTime, endTime;
	double avgTime = 0.0, sumTime = 0.0;
	
	for(int i = 0; i < REPEAT; i++) {
		time(&startTime);
		kernelCompC(arr, arr, n);
		time(&endTime);
		sumTime += difftime(endTime, startTime);
	}
	avgTime = sumTime / REPEAT;
	printf("Average computation time for n = %d (C, %dx): %lfs\n", n, REPEAT, avgTime);
	
	if (RUNWITHASM){
		for(int i = 0; i < REPEAT; i++) {
			time(&startTime);
			sdotComp(arr, arr, n);
			time(&endTime);
			sumTime += difftime(endTime, startTime);
		}
		avgTime = sumTime / REPEAT;
		printf("Average computation time for n = %d (ASM, %dx): %lfs\n", n, REPEAT, avgTime);
	}
}
