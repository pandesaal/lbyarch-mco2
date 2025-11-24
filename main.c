#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kernel.c"

#define REPEAT 30

int main() {
	
	float *arr = initArr();
	
	int choice = 0;
	int n = 0
	float result = 0;
	
	printf("[1] - [4]: input sizes for vectors\n")
	printf("[1] 2^20\n");
	printf("[2] 2^24\n");
	printf("[3] 2^30\n");
	printf("[4] Custom length\n");
	printf("[5] Exit\n");
	printf("Enter choice: ");
	scanf("%d", &choice);
	
	switch (choice){
		case 1:
			n = ARRMAX20;
			break;
		case 2:
			n = ARRMAX24;
			break;
		case 3:
			n = ARRMAX30;
			break;
		case 4:
			printf("Enter length of vector: ");
			scanf("%d", &n);
		default:
			printf("")
	}
	
	result = sdotComp(arr, arr, n);
	printf("Dot product (ASM check): %f\n", result);
	if (SANITY) sanityCheck(arr, arr, n);
	
	free(arr);
	return 0;
}
