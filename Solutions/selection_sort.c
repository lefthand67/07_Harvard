// VR implementation
#include <stdio.h>

int main(void)
{
    int n = 6;
    // int array_length = n;
    int array[n];

    // array initialization
    array[0] = 6;
    array[1] = 4;
    array[2] = 3;
    array[3] = 5;
    array[4] = 2;
    array[5] = 1;

    // print initial array
    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }

    // sorting
    for (int i = 0; i < n-1; i++)
    {
        // set array[i] as a minimal value
        int min_value = array[i];
        // fix the index of the minimal value
        int min_val_index = i;
        
        // compare each number to all the others
        for (int j = i+1; j < n; j++)
        {
            // set a new miinimal value and its index
            if (array[j] < min_value)
            {
                min_value = array[j];
                min_val_index = j;
            }
        }
        
        // swap values
        int temp = array[i];
        array[i] = min_value;
        array[min_val_index] = temp;
    }

    // print final array
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}