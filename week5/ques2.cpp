/*Given an unsorted array of integers, 
design an algorithm and implement it using a program to find
 whether two elements exist such that their sum is equal to the given key element.(Time Complexity = O(n log n))*/
#include <stdio.h> #define MAX 100
 void find(int A[], int n, int key)
{
    int flag = 0;
    int lb = 0, ub = n;
    while (lb < ub)
    {

        if (A[lb] + A[ub] == key)
        {
            flag = 1;
            printf("%d\t%d,", A[lb], A[ub]);
            lb++;
            ub--;
        }
        else if (A[lb] + A[ub] < key)
            lb++;
        else
            ub--;
    }
    if (flag == 0)
        printf("No sequence found");
}
void merge_sort(int A[], int lb, int ub)
{

    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        merge_sort(A, lb, mid);
        merge_sort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}
void merge(int A[], int lb, int mid, int ub)
{

    int n1 = mid + 1 - lb;
    int n2 = ub - mid;
    int L[MAX], R[MAX];
    for (int i = 0; i < n1; i++)
        L[i] = A[lb + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + j + 1];

    int i = 0, j = 0, k = lb;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
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
}
int main()
{
    int key;
    int t, n, A[MAX];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
    }
    scanf("%d", &key);
    merge_sort(A, 0, n - 1);

    find(A, n, key);
}
