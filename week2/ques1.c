/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n)) */
#include<stdio.h> int main() 
{     int t; 
    printf("enter the no of test cases:");     scanf("%d", &t); 
 
    while(t) 
    { 
        int n; 
        printf("enter the size of array:");         scanf("%d", &n);         printf("enter the elements of array:"); 
        int arr[n]; 
        int i; 
        for(i=0; i<n; i++)             scanf("%d", &arr[i]); 
 
 
        int key; 
        printf("enter the key:");         scanf("%d", &key); 
 
        int occur1=0,occur2=0,l=0, r=n; 
 
        while(l<=r) 
        { 
            int mid = l + (r-l)/2;             if(arr[mid]>key){                 r=mid-1; 
            } 
            else if(arr[mid]<key)                 l=mid+1;             else 
            { 
                occur1=mid;                 occur2=mid;                 while(arr[occur1]==arr[mid]) 
                    occur1--; 
                while(arr[occur2]==arr[mid]) 
                    occur2++;                     break; 
            } 
        } 
 
        printf("%d occurs %d times\n", key,(occur2-occur1)-1); 
 
    t--;     } 
} 
