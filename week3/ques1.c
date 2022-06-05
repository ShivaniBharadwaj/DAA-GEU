/*Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort.
 Your program should be able to find number of comparisons and shifts 
 ( shifts - total number of times the array elements are shifted from their place) required for sorting the array.*/
#include <stdio.h> 
 	 
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {
        int n, comp = 0, shift = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for (int i = 1; i < n; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
                comp++;
                shift++;
            }
            arr[j + 1] = temp;
            shift++;
        }

        printf("No of shifts and no of comparisions: %d, %d\n", shift, comp);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        t--;
    }
}

