//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int start, int mid, int end)
    {
        int n = end - start +1;
        int merged[n];
        int i1 = start, i2 = mid+1;
        int x = 0;
        while(i1<= mid && i2 <= end ){
            if(arr[i1]<= arr[i2])merged[x++] = arr[i1++];
            else merged[x++] = arr[i2++];
        }
        while(i1<= mid)merged[x++] = arr[i1++];
        while(i2 <= end) merged[x++] =arr[i2++];
        for(int i=0, j = start; i< n; j++, i++)arr[j]  = merged[i];
    }
    public:
    void mergeSort(int arr[], int start, int end)
    {
        if(start >= end)return;
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends