# LBYARCH MCO2

The task is to create a program in x86-64 Assembly and C that will calculate the dot product of a predefined matrix. The inputs used to test their performances were 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup>, which all push the computational limits of the system and the full capacity of the single-precision float. The two programs are benchmarked and compared against each other to understand the differences between different levels of programming languages.

## Group Members

-   Domingo, Angela Sophia D.

## Comparative Execution Time and Kernel Performances

To benchmark the kernels, each function was tested 30 times and their averages were used as the metric of comparison.

**2<sup>20</sup>**: Both the programs performed an average of sub-zero seconds, showing that the languages had no issues in performing their calculations for repeated inputs of this size.

**2<sup>24</sup>**: There were noticable delays during testing, but both languages performed relatively fast compared to n = 2<sup>20</sup>. C and ASM had the same average computation time of 0.066667 seconds - nearing a second slower than the average of 2<sup>20</sup>.

**2<sup>30</sup>**: This ran the slowest, taking 4 minutes in real life for both kernels to compute. Most runs show C as the slower kernel, but sometimes Assembly ranks slower. This can be attributed to C's structure having more overhead to accomodate higher-level coding syntax. The C function below was able to do everything the entire `asmfuncs.asm` file was designated to do. In the times Assembly ran slower than C, there were small changes to the source code that required the program to be recompiled and ran again.

```C
float kernelCompC(float *array1, float *array2, int size){
	float res = 0.0;
	float mul = 0.0;
	for (int i = 0; i < size; i++){
		mul = array1[i]*array2[i];
		res += mul;
	}
	return res;
}
```

It can be inferred that there are computational drawbacks for choosing C instead of Assembly. However, it can't be denied that Assembly has a steep learning curve due to it working closely with machine-level code despite its favorable runtimes.

## C Correctness Check

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/04adbbc3-732b-42a1-a985-cd0a59fa00b0" />

## ASM with C Correctness Check

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/861f2067-9305-475a-92bb-00b68c7e0c58" />

## Demo Video

[Google Drive](https://drive.google.com/drive/folders/1qGL_dpXxNA2TG1RIKRlHa88ZMnTneFlo?usp=sharing)
