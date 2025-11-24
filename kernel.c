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
    	arr[i] = rand();
	}
	
	return arr;
}

float kernelCompC(float *array1, float *array2, int size){
	float res = 0.0;
	float mul = 0.0;
	for (int i = 0; i < size; i++){
		mul = array1[i]*array2[i];
		res += mul;
	}
	
	return res;
}

void run(float *array1, float *array2, int n){
	if (SANITY) {
		float resC = kernelCompC(array1, array2, n);
		printf("Dot product (C check):	 %f\n", resC);
		
		if (RUNWITHASM){
			float resASM = sdotComp(array1, array2, n);        
			printf("Dot product (ASM check): %f\n", resASM);                                
		}
	}
	
	time_t startTime, endTime;
	double avgTime = 0.0, sumTime = 0.0;
	
	for(int i = 0; i < REPEAT; i++) {
		time(&startTime);
		kernelCompC(array1, array2, n);
		time(&endTime);
		sumTime += difftime(endTime, startTime);
	}
	avgTime = sumTime / REPEAT;
	printf("Average computation time for n = %d (C, %dx): %lfs\n", n, REPEAT, avgTime);
	
	if (RUNWITHASM){
		avgTime = 0.0;
		sumTime = 0.0;
		
		for(int i = 0; i < REPEAT; i++) {
			time(&startTime);
			sdotComp(array1, array2, n);
			time(&endTime);
			sumTime += difftime(endTime, startTime);
		}
		avgTime = sumTime / REPEAT;
		printf("Average computation time for n = %d (ASM, %dx): %lfs\n", n, REPEAT, avgTime);
	}
}
