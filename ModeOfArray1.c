// Sarah Chow
// Find the mode of an array, version 1

#include <stdio.h>
#include <stdlib.h>

double modeOfArray(int arr[], int n)
{
	int moreThanOnce = 1; // False, boolean value


    // vals[n][0]: value, vals[n][1]: total times value appears
    int *vals[n];

    for (int i = 0; i < n; i++)
    {
	    vals[i] = (int*)malloc(2 * sizeof(int)); // Each array element has memory allocated for two integers, creates a column of integers

    }

	int counter = 0; // Counter for the array vals

	int maxValCounter;
    int maxValIndex;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
            for (int i = 0; i < counter; i++)
            {
                printf("TEST\t%d\t%d\n", vals[i][0], vals[i][1]); // Display the current array (value and number of occurances)
            }

            printf("\n\n");


			if (arr[i] == vals[j][0]) // If value has already been accounted for, this is a duplicate of one of the values in the array
			{
				moreThanOnce = 0; // True
                vals[j][1] += 1; // Increase number of occurances of this value
			}
			
		}

		if (moreThanOnce != 0) // Did not come across this value yet
		{
			vals[counter][0] = arr[i]; // Add the value to the first row of the array
            vals[counter][1] = 1; // Set the number of occurances to 1
            
			counter++;
		}

        moreThanOnce = 1; // Reset bool value

        
	}

    // Find most common value, compare number of occurances of each value in array
    maxValIndex = vals[0][0];
    maxValCounter = vals[0][1];

	for (int i = 0; i < counter; i++)
	{
		if (vals[i][1] > maxValCounter)
		{
			maxValCounter = vals[i][1];
            maxValIndex = vals[i][0];
		}
	}

	for (int i = 0; i < n; i++)
	{
		free (vals[i]);
	}
	

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
