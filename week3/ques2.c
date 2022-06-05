/*Given an unsorted array of integers, design an algorithm and implement a
 program to sort this array using selection sort.
 Your program should also find number of comparisons and number of swaps required.*/

#include <stdio.h>
void swap(int *i, int *j);
int main()
{
    int t;
    scanf("%d", &t);
    while (t)
    {

        int n, comp = 0, swap1 = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        for (int i = 0; i <= n - 2; i++)
        {
            int min = i;
            for (int j = i + 1; j <= n - 1; j++)
            {
                comp++;
                if (arr[j] < arr[min])
                    min = j;
            }
            swap1++;
            swap(&arr[i], &arr[min]);
        }

        printf("No of swap and no of comparisions: %d %d\n", swap1, comp);
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        t--;
    }
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

