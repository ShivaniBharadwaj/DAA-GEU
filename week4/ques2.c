
/*.  Given an unsorted array of integers, design an algorithm and implement it using a
 program  to sort an array of elements by partitioning the array into two subarrays based on a pivot element
  such that one of the sub array holds values smaller than the pivot element while another sub array holds values 
  greater than the pivot element. Pivot element should be selected randomly from the array.
 Your program should also find number of comparisons and swaps required for sorting the array*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> #define MAX 100  int swaps=0,compare=0;
int partition(int A[], int low, int high) int pivot = A[low];
int i = low - 1;
int j = high + 1;
if (i >= j)
    return j;

while (1)
{
    compare++;
    do
    {
        i++;
    } while (A[i] < pivot);
    do
    {

        j--;

    } while (A[j] > pivot);

    if (i >= j)
        return j;

    else
    {
        int temp = A[i];

        A[i] = A[j];
        A[j] = temp;
        swaps++;
    }
}
}
int partition_random(int A[], int low, int high)
{

    srand(time(NULL));
    int random = low + rand() % (high - low);
    {

        int temp = A[random];
        A[random] = A[low];
        A[low] = temp;
        swaps++;
    }

    return partition(A, low, high);
}

void Quick_sort(int A[], int low, int high)
{

    if (low < high)
    {
        int part = partition_random(A, low, high);
        printf("%d", part);
        Quick_sort(A, low, part);
        Quick_sort(A, part + 1, high);
    }
}
int main()
{

    int A[MAX], n;
    printf("Enter the number f elements in tha array :");
    scanf("%d", &n);
    printf("Enter the elements in the array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    Quick_sort(A, 0, n - 1);
    printf("Sorted array is :");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("total comparisons :%d", compare);
    printf("total swaps :%d", swaps);
    return 0;
}

