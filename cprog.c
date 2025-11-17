#include <stdio.h>

//extern void hewo(); // asm function
//int main() {
//	
//	hewo();
//	return 0;
//}

extern float sdotComp(int size);

int main() {
	
	int n = 0;
	float result = 0;
	
	printf("Enter length of vector (int): ");
	scanf("%d", &n);
	
	result = sdotComp(n);
	printf("Dot product: %f\n", result);
	
	return 0;
}
