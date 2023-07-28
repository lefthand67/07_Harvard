// VR implementation
#include <stdio.h>

int main(void)
{
    int n = 6;
    int array_length = n;
    int array[n];

    // array initialization
    array[0] = 6;
    array[1] = 4;
    array[2] = 3;
    array[3] = 5;
    array[4] = 2;
    array[5] = 1;

    // print initial array
    for (int i = 0; i < array_length; i++)
    {
        printf("%i ", array[i]);
    }

    // sorting
    int counter = -1;
    while (counter != 0)
    {
        counter = 0;
        // comparing pairs
        for (int i = 0; i < array_length-1; i++)
        {
            // swap values
            if (array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                // add 1 to counter
                counter++;
            }
        }
        // reduce the cycle number by one
        array_length--;
    }

    // print final array
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

}