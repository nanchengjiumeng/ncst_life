#include <stdio.h>

void heapSort(int H[],int);
void heapAdjust(int H[],int, int, int);
void printSequence(int H[],int);
void printLine(int ,int );


int main(void)
{
	//int i; 
	//for(i=0;i<10;i++)  
	//	scanf("%d",&a[i]); 
	int H[] = {49,38,65,97,76,13,27,55,33,44};
	printf("\n   The unsorted sequence is:\n\n\t\t");
	printSequence(H,10);
	puts("");
	
	heapSort(H,10);
	printf("   The sorted sequence is:\n\n\t\t");
	printSequence(H,10);
	puts("");

	return 0;
}

void heapSort(int H[],int length)
{
	int i,j,temp;
	//Initialize a Heap
	for ( i = length/2-1; i >= 0; i-- )
	{
		heapAdjust(H, i, length, length);
	}
	printf("   The following sequence is a heap after HeapAdjust.\n\n\t\t");
	printSequence(H,length);
	puts("");
	//Sort

	printf("   The sorting procedures are:\n\n");
	printf("***************************************************************\n\n");
	for(i = length-1; i >= 1; i--)
	{
		printf("\tBefore move:\n\n\t\t");
		printSequence(H,length);
		printf("\t\t");
		printLine(0,i+1);
		//move element.
		temp = H[0]; 
		H[0] = H[i]; 
		H[i] = temp; 
		
		printf("\tAfter move element:\n\n\t\t");
		printSequence(H,length);
		printf("\t\t");
		printLine(0,i+1);

        //heap adjust
		heapAdjust(H , 0 , i, length);

		printf("\tAfter heap adjust:\n\n\t\t");
		printSequence(H,length);
		puts("\n");
		printf("***************************************************************\n\n");
	}
}

void heapAdjust(int H[],int begin, int end, int lengthOfH)
{
	// Adjust one pass 
	int rp;
	int k;
	k = 2 * begin + 1;
	rp = H[begin];

	while ( k < end )
	{
		if ( ( k < end -1 ) && ( H[k] < H[k+1] ) )
		{
			k++;
		}
		if ( rp < H[k] )
		{
			H[begin] = H[k];
			begin = k;
			k = 2 * begin + 1;
		}
		else
		{
			break;
		}
	}
	H[begin] = rp;

	//printSequence(H,lengthOfH);
}
void printSequence(int H[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",H[i]);
	}
	puts("");

}

void printLine(int begin,int end)
{
	int i;
	for(i=begin;i<end;i++)
	{
		if (i == begin)
		{
			printf(" ^-");
		}
		else if (i == end-1)
		{
			printf("^");			
		}
		else
		{
			printf("---");
		}
		
	}
	puts("");
}

