#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialProgram(int mode, int data[], int size, char dataString[][20], int sizeString);
void quickSortWithString(char array[][20], int left, int right);
void printArrayString(char array[][20], int size);
void quickSort(int array[], int left, int right);
void printArray(int array[], int size);

void quickSortWithString(char array[][20], int left, int right)
{
    if(left < right)
    {
        char pivo[20];
        int i, j;

        char done[20];

        strcpy(pivo, array[right]);

        for(i=left, j=left; i<right; i++)
        {
            if(strcmp(array[i], pivo)<0)
            {
                strcpy(done, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], done);

                j++;
            }
        }

        strcpy(array[i], array[j]);
        strcpy(array[j], pivo);

        quickSortWithString(array, 0, j-1);
        quickSortWithString(array, j+1, i);

    }     
}

void quickSort(int array[], int left, int right)
{
    if(left < right)
    {
        int pivo = array[right];
        int i, j;

        int done;

        for(i=left, j=left; i<right; i++)
        {
            if(array[i]<pivo)
            {
                done = array[i];
                array[i] = array[j];
                array[j] = done;

                j++;
            }
        }

        array[i] = array[j];
        array[j] = pivo;

        quickSort(array, 0, j-1);
        quickSort(array, j+1, i);

    }
}

void printArrayString(char array[][20], int size)
{
    printf("Sorted Array in Ascending Order:\n");

    for (int i=0; i<size; ++i)
    {
        printf("%s  ", array[i]);
    }

    printf("\n");
}

void printArray(int array[], int size)
{
    printf("Sorted Array in Ascending Order:\n");

    for (int i=0; i<size; ++i)
    {
        printf("%d  ", array[i]);
    }

    printf("\n");
}

void initialProgram(int mode, int data[], int size, char dataString[][20], int sizeString)
{
    switch (mode)
    {
    case 1:
        quickSort(data, 0, size-1);
        printArray(data, size);
        break;
    case 2:
        quickSortWithString(dataString, 0, sizeString-1);
        printArrayString(dataString, sizeString);
        break;
    default:
        printf("\nKey Invalid!");
    }
}

int main()
{
    int data[] = {4,7,2,5,12,17,11,10,107,6,4,1,8,3};

    char dataString[][20] =
    {
        "Eduardo",
        "Amanda",
        "Beatriz",
        "Joao",
        "Pedro",
        "Julia",
        "Ricardo"
    };

    int size = sizeof(data) / sizeof(data[0]);

    int sizeString = sizeof(dataString) / sizeof(dataString[0]);

    int mode;

    printf("\nChoose your mode: ");
    printf("\n1 - QuickSort Normal");
    printf("\n2 - QuickSort With Strings");
    printf("\n-> ");
    scanf(" %d", &mode);

    initialProgram(mode, data, size, dataString, sizeString);

}