#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort( int array[], int length );
void sortSubArray( int array[], int low, int high );
void merge( int array[], int left, int middle, int middle2, int right );
void displayElements( int array[], int lenght );
void displaySubArray( int array[], int left, int right);

int main( void )
{
	int array[ SIZE ];
	int i;

	srand( time( NULL ) );

	for( i = 0; i < SIZE; i++ )
		array[ i ] = rand() % 90 + 10;
	printf("Unsorted array:\n");
	displayElements( array, SIZE );
	printf( "\n\n" );
	mergeSort( array, SIZE );
	printf( "Sorted array:\n " );
	displayElements( array, SIZE );
	
	printf( "\n" );
	return 0;
}

void mergeSort( int array[], int length )
{
	sortSubArray( array, 0, length - 1 );
}

void sortSubArray( int array[], int low, int high )
{
	int middle1, middle2;

	if( ( high - low ) >=1 )
	{
		middle1 = ( low + high ) / 2;
		middle2 = middle1 +1;

		printf( "split:  " );
		displaySubArray( array, low, high );
		printf( "\n        " );
		displaySubArray( array, low, middle1 );
		printf( "\n        " );
		displaySubArray( array, middle2, high );
		printf( "\n\n" );

		sortSubArray( array, low, middle1 );
		sortSubArray( array, middle2, high );

		merge( array, low, middle1, middle2, high );
	}
}

void merge( int array[], int left, int middle1, int middle2, int right )
{
	int leftIndex = left;
	int rightIndex = middle2;
	int combineIndex = left;
	int tempArray[ SIZE ];
	int i;

	printf( "merge:  " );
	displaySubArray( array, left, middle1 );
	printf( "\n        " );
	displaySubArray( array, middle1, right );
	printf( "\n" );

	while( leftIndex <= middle1 && rightIndex <= right )
	{
		if( array[ leftIndex ] <= array[ rightIndex ] )
			tempArray[ combineIndex++ ] = array[ leftIndex++ ];
		else
			tempArray[ combineIndex++ ] = array[ rightIndex++ ];
	}

	if( leftIndex == middle2 )
	{
		while( rightIndex <= right )
			tempArray[ combineIndex++ ] = array[ rightIndex++ ];
	}
	else
	{
		while( leftIndex <= middle1 )
			tempArray[ combineIndex++ ] = array[ leftIndex++ ];		
	}

	for( i = left; i <= right; i++ )
	{
		array[ i ] = tempArray[ i ];
	}

	printf( "        " );
	displaySubArray( array, left, right );
	printf( "\n\n" );
}

void displayElements( int array[], int length )
{
	displaySubArray( array, 0, length - 1);
}

void displaySubArray( int array[], int left, int right )
{
	int i;

	for( i = 0; i < left; i++ )
		printf( "   " );
	for( i = left; i <= right; i++ )
		printf( " %d", array[ i ] );
}