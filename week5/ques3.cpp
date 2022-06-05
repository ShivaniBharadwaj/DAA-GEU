/*You have been given two sorted integer arrays of size m and n.
Design an algorithm and implement it using 
a program to find list of elements which are common to both.(Time Complexity = O(m + n))*/

#include <stdio.h>
#define MAX 100
    void common(int A1[], int A2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (A1[i] < A2[j])
        {
            i++;
        }
        else if (A1[i] > A2[j])
        {
            j++;
        }
        else
        {
            printf("%d\t", A2[j++]);
            i++;
        }
    }
}
int main()
{
    int t, A1[MAX], A2[MAX], n, m;
    scanf("%d", &t);
    while (t--)
    {
        printf("Enter size of A1:");
        scanf("%d", &m);
        printf("Enter the elements in the array :");
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &A1[i]);
        }
        printf("Enter size of A2:");
        scanf("%d", &n);
        printf("Enter the elements in the array :");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &A2[i]);
        }
        common(A1, A2, m, n);
    }
}
