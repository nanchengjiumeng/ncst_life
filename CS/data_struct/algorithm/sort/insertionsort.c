#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort( int array[], int length );
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
	insertionSort( array, SIZE );
	printf("Sorted array:\n");

	for( i = 0; i < SIZE; i++ )
		printf("%d ", array[ i ]);

	printf( "\n\n" );

	return 0;
}

void insertionSort( int array[], int length )
{
	int insert;
	int i;

	for( i = 1; i < length; i++)
	{
		int moveItem = i;
		insert = array[ i ];

		while( moveItem > 0 && array[ moveItem - 1 ] > insert )
		{
			array[ moveItem ] = array[ moveItem - 1 ];
			--moveItem;
		}

		array[ moveItem ] = insert;

		printPass( array, length, i, moveItem );
	}
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

	for( i = 0; i <= pass; i++ )
		printf("--  ");

	printf("\n");
}