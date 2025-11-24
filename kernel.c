#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRMAX20 1048576
#define ARRMAX24 16777216
#define ARRMAX30 1073741824
#define SANITY 1

extern float sdotComp(float *array1, float *array2, int size);

float* initArr() {
	float *arr = (float *)malloc(sizeof(float) * ARRMAX30);
	if (arr == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    
    for (int i = 0; i < ARRMAX30; i++){
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
