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

