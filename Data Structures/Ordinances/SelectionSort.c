#include <stdio.h>
#include <stdlib.h>

void selectionSort(int array[], int size);
void printArray(int array[], int size);

void selectionSort(int array[], int size)
{
    register int a, b, c;
    int exchange;

    char t;
    
    for (a=0; a<size-1; ++a)
    {
        exchange = 0;
        c = a;
        t = array[a];

        for(b=a+1; b<size; ++b)
        {
            if (array[b] < t)
            {
                c = b;
                t = array[b];
                exchange = 1;
            }
        }
        if (exchange)
        {
            array[c] = array[a];
            array[a] = t;
        }
    }
}

void printArray(int array[], int size)
{

    for (int i=0; i<size; ++i)
    {
        printf("%d  ", array[i]);
    }

    printf("\n");
}

int main()
{
    int data[] = {3, 7, 2, 8, 1, 6};

    int size = sizeof(data) / sizeof(data[0]);

    selectionSort(data, size);

    printf("Sorted Array in Ascending Order:\n");

    printArray(data, size);
}