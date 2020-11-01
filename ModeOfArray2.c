// Sarah Chow
// Find the mode of an array, version 2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double modeOfArray(int arr[], int n)
{
	int moreThanOnce = 1; // False, boolean value

    int *vals = (int*)malloc(n * 2 * sizeof(int)); // Allocate memory for the entire array, number of elements * 2 rows
	assert(vals != NULL);

    /* To access the array values, *(arrayName + (columnNumber * numberOfRows) + index in column)

    Example: 
    1   2   3   4
    5   6   7   8
    9   10  11  12

    arrayName: gives location of first array of the element
    (columnNumber * numberOfRows): locates first element in the desired column
    index in column: locates correct element

    If wanted number 7: *(arrayName + (2 * 3) + 1)

    */


    
	int counter = 0; // Counter for the array vals

	int maxValCounter;
    int maxValIndex;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
            for (int i = 0; i < counter; i++)
            {
                printf("TEST\t%d\t%d\n", *(vals + (i * 2) + 0), *(vals + (i * 2) + 1)); // Display the array
            }

            printf("\n\n");


			if (arr[i] == *(vals + (j * 2) + 0)) // Accessing column j, element 0
			{
				moreThanOnce = 0; // True
                *(vals + j*2 + 1) += 1; // Increase number of times passed this value
			}
            

			
		}

		if (moreThanOnce != 0) // Did not come across this value yet
		{
			*(vals + counter * 2 + 0) = arr[i]; // Set new counter column, element 0 to value
            *(vals + counter * 2 + 1) = 1; // Set new counter column element 1 to 1 (number of occurances of the value)
            
			counter++;
		}

        moreThanOnce = 1; // reset bool value

        
	}

	maxValCounter = *(vals + 0 + 1);
    maxValIndex = *(vals + 0 + 0);

	for (int i = 0; i < counter; i++)
	{
		if (*(vals + i * 2 + 1) > maxValCounter)
		{
			maxValCounter = *(vals + i * 2 + 1);
            maxValIndex = *(vals + i * 2 + 0);

           

            
		}
	}

	free(vals);

	return (maxValIndex);



}

int main(void)
{

	const int SIZE = 10;
	int array[] = { 2, 3, 5, 2, 3, 4, 6, 8, 2, 1 };
    int arr[] = {4, 4, 3, 5, 5, 5, 3, 1, 2, 5, 7, 9};

	double mode;

	mode = modeOfArray(arr, sizeof(arr)/sizeof(arr[0]));

	printf("%lf\n", mode);

	return 0;
}
