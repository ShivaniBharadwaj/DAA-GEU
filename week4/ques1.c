/*Given an unsorted array of integers, design an algorithm
 and implement it using a program to sort an array of elements by dividing the array into
  two subarrays and combining these subarrays after sorting each one of them.
  Your program should also find number of comparisons and inversions during sorting the array.*/
#include <stdio.h>
 #define MAX 100
    int comparisons=0;
 int merge_sort(int A[], int lb, int ub);
int merge(int A[], int lb, int mid, int ub);
int merge_sort(int A[], int lb, int ub)
{
    int inversions = 0;

    if (lb < ub)
    {

        int mid = lb + (ub - lb) / 2;

        inversions += merge_sort(A, lb, mid);

        inversions += merge_sort(A, mid + 1, ub);

        inversions += merge(A, lb, mid, ub);
    }
    return inversions;
}
int merge(int A[], int lb, int mid, int ub)
{
    int inversioncount = 0;
    int n1 = mid + 1 - lb;
    int n2 = ub - mid;
    int L[MAX], R[MAX];
    for (int
             i = 0;
         i < n1; i++)
        L[i] = A[lb + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];

    int i = 0, j = 0, k = lb;
    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {
            comparisons++;
            A[k] = L[i];
            i++;
        }
        else
        {
            comparisons++;
            A[k] = R[j];
            j++;
            inversioncount = inversioncount + (mid - i);
        }
        k++;
    }
    while (i < n1)
    {

        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {

        A[k] = R[j];
        j++;
        k++;
    }
    return inversioncount;
}

int main()
{
    int count = 0;
    int n, t, A[MAX];
    printf("Enter the test cases :");
    scanf("%d", &t);
    while (t--)
    {
        printf("Enter the size of the array :");
        scanf("%d", &n);
        printf("Enter the elements in the array :");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        count = merge_sort(A, 0, n - 1);
        printf("Sorted Array is :");
        for (int i = 0; i < n; i++)
        {

            printf("%d\t", A[i]);
        }
    }
    printf("Total inversions%d and comparisons %d ", count, comparisons);
    return 0;
}
