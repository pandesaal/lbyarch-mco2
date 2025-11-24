#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kernel.c"

int main() {
	
	srand(0);
	float *arr1 = initArr();
	float *arr2 = initArr();
	
	char choice = '0';
	int n = 0;
	float result = 0;
	
	while (choice != '5') {
		
		printf("[1] - [4]: input sizes for vectors\n");
		printf("[1] 2^20\n");
		printf("[2] 2^24\n");
		printf("[3] 2^30\n");
		printf("[4] Custom length\n");
		printf("[5] Exit\n");
		printf("Enter choice: ");
		scanf(" %c", &choice);
		
		switch (choice){
			case '1':
				n = ARRMAX20;
				run(arr1, arr2, n);
				break;
			case '2':
				n = ARRMAX24;
				run(arr1, arr2, n);
				break;
			case '3':
				n = ARRMAX30;
				run(arr1, arr2, n);
				break;
			case '4':
				printf("Enter length of vector: ");
				scanf("%d", &n);
				if (n > 0) run(arr1, arr2, n);
				else printf("Invalid input, please try again.\n");
				break;
			case '5':
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid input, please try again.\n");
				break;
		}
	}
	
	free(arr1);
	free(arr2);
	return 0;
}
