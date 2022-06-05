Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K. 
#include<stdio.h> #include <stdlib.h> int main(){ 
    int t; 
    scanf("%d", &t);     while(t){ 
        int n; 
        scanf("%d", &n); 
        int arr[n]; 
        int i; 
        for(i=0;i<n;i++)             scanf("%d", &arr[i]);         int k,count=0;         scanf("%d", &k);         for(i=0;i<n;i++){          	int j;             for(j=1; j<n; j++)                 if(arr[j]-arr[i]==k) {                         count++; 
                    }} 
        printf("%d pairs found", count); 
        t--; 
    } 
} 
