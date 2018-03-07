#include <stdio.h>
#include <stdlib.h>

//#define length 20
//int R_Array[] = {14,10,11,5,6,15,0,15,16,14,0,8,17,15,7,19,17,1,18,7};
#define length 8
int R_Array[] = {49, 38, 65, 97, 76, 13, 27, 49};


void swap(int R[],int i,int j);
void quickSort(int R[],int left,int right);
void quickSortPass(int R[],int i,int j, int * pivotPtr);
void printArray(int R[], int n);
void printSubArray(int R[], int begin, int end, int len);

int main(void)
{
	puts("The original sequence is :");
	printArray(R_Array, length);
	puts("");

	quickSort(R_Array, 0, length-1);

	puts("The result sequence is :");
	printArray(R_Array, length);
	puts("");
	return 0;
}

void swap(int R[],int i,int j)
{
	int temp;
	temp = R[i];
	R[i] = R[j];
	R[j] = temp;
}

void quickSortPass(int R[], int i,int j,int *pivotPtr)
{
	//I is the beginning point and j is the end point, *pivotPtr is the pointer which point to the pivot.
	//This function can be changed into a function with the result of pivot subscript
	
	int end;      //  indicates the end side element which will compare with the pivot
	int x;        //  indicates the pivot value
	int rp;       //  indicates the pivot value in the progressed algorithm

	end = j;
	x = R[i];
	*pivotPtr = i;

	
		
	printf("Focus on the following sequence:\n");
	printSubArray(R,i,j,length);
	printf("The pivot is %d.\n",R[*pivotPtr]);

    //Quick sort one pass which is according to Weimin Yan's algorithm.
	//pivot starts form the first element of the R's some substring.

	while ( *pivotPtr < end)
	{
		while ( (*pivotPtr < end) && (R[end] >= x))     //find the pisition of the element which is less than the pivot
		{
			end = end - 1;
		}
		swap(R,*pivotPtr,end);                           //swap the element

		while ( (*pivotPtr < end) && (R[*pivotPtr] <= x))   //find the pisition of the element which is greater than the pivot
		{
			*pivotPtr = *pivotPtr + 1;
		}
		swap(R,*pivotPtr,end);	                            //swap the element
	}

/*  
    //the progressed method 
	rp = R[*pivotPtr];
	while ( *pivotPtr < end)
	{
		while ( (*pivotPtr < end) && (R[end] >= x))      //find the pisition of the element which is less than the pivot
		{
			end = end - 1;
		}
		R[*pivotPtr] = R[end];                            //assign the element
		
		while ( (*pivotPtr < end) && (R[*pivotPtr] <= x))   //find the pisition of the element which is greater than the pivot
		{
			*pivotPtr = *pivotPtr + 1;
		}
		R[end] = R[*pivotPtr];                            //assign the element
	}
	R[*pivotPtr] = rp;
*/


	printf("After one pass.\n");
	printArray(R_Array, length);
	puts("");
}

void quickSort(int R[], int left, int right)
{
	int  pivot;
	if (left < right)
	{
		quickSortPass(R,left,right,&pivot);
		quickSort(R,left,pivot-1);
		quickSort(R,pivot+1,right);
	}
}

void printArray(int R[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", R[i]);
	}
	printf("\n");
}

void printSubArray(int R[], int begin, int end, int len)
{
	int i;
	for(i = 0; i < length ; i++)
	{
		if ((i>=begin) && (i<=end))
		{
			printf("%d ", R[i]);
		}
		else
		{
			printf("   ");
		}		
	}
	printf("\n");
}