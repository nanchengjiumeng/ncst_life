#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort( int array[], int length );
void swap( int array[], int first, int second );
void printPass( int array[], int length, int pass, int index);

int main( void )
{
	int array[ SIZE ];
	int i;

	srand( time( NULL ) );

	for( i = 0; i < SIZE; i++ )
		array[ i ] = rand() % 90 + 10;

	printf("Unsorted array:\n");

	for( i = 0; i < SIZE; i++ )
		printf("%d ", array[ i ]);

	printf( "\n\n" );
	selectionSort( array, SIZE );
	printf("Sorted array:\n");

	for( i = 0; i < SIZE; i++ )
		printf("%d ", array[ i ]);

	printf( "\n\n" );

	return 0;
}

void selectionSort( int array[], int length )
{
	int smallest;
	int i,j;

	for( i = 0; i < length; i++)
	{
		smallest = i;
		for( j = i + 1; j < length; j++)
			if( array[ j ] < array[ smallest ] )
				smallest = j;

		swap( array, i, smallest);
		printPass( array, length, i + 1, smallest );
	}
}

void swap( int array[], int first, int second )
{
	int temp;
	temp = array[ first ];
	array[ first ] = array[ second ];
	array[ second ] = temp;
}

void printPass( int array[], int length, int pass, int index)
{
	int i;
	printf("After pass %2d: ", pass);

	for( i = 0; i < index; i++ )
		printf("%d  ", array[ i ]);
	
	printf("%d* ", array[ index ]);
	
	for( i = index + 1; i < length; i++ )
		printf("%d  ", array[ i ]);

	printf("\n               ");

	for( i = 0; i < pass; i++ )
		printf("--  ");

	printf("\n");
}