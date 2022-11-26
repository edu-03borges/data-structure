#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size);
void printArray(int array[], int size);

void insertionSort(int array[], int size)
{
    register int i, j;
    int done;

    for(i=1;i<size;++i)
    {
        done = array[i];
        
        for(j=i-1; j>=0 && done<array[j];--j)
        {
            array[j+1] = array[j];
        }

        array[j+1] = done;
    }
}

void printArray(int array[], int size)
{

    for (int i=0;i<size;++i)
    {
        printf("%d  ", array[i]);
    }

    printf("\n");
}

int main()
{
    int data[] = {3, 7, 2, 8, 1, 6};

    int size = sizeof(data) / sizeof(data[0]);

    insertionSort(data, size);

    printf("Sorted Array in Ascending Order:\n");

    printArray(data, size);
}