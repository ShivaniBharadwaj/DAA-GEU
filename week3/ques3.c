/*Given an unsorted array of positive integers,
 design an algorithm and implement it using a program 
 to find whether there are any duplicate elements in the array or not .(use sorting)(Time Complexity = O(n log n))*/

#include <stdio.h>
void findDuplicate(int arr[], int n);
void sort(int arr[], int l, int r);
void merge(int a[], int l, int m, int r);
int main()
{
    int t;
    printf("Enter test cases: ");
    scanf("%d", &t);
    while (t)
    {
        int n;
        printf("\nEnter Size of array: ");
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        findDuplicate(arr, n);
        t--;
    }
}
void findDuplicate(int arr[], int n)
{
    sort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf(",YES");
    else
        printf(",NO");
}
void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        sort(arr, l, mid);
        sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + i + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
            k++;
        }
        else
        {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
