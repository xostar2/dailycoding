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
//{ Driver Code Starts


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         
         int len1=m-l+1;
         int len2=r-m;
         int *first= new int [len1];
         int *second=new int [len2];
         int index=l;
         for(int i=0 ; i<len1 ; i++){
             first[i]=arr[index++];
         }
         
         for(int i=0 ; i<len2 ; i++){
             second [i]=arr[index++];
         }
         
         int in1=0;
         int in2=0;
         index=l;
         
         while(in1<len1 && in2<len2){
             
             if(first[in1]<second[in2]){
                 arr[index++]=first[in1++];
             }
             else{
                 arr[index++]=second[in2++];
             }
             
         }
         
         while(in1<len1){
             arr[index++]=first[in1++];
         }
         while(in2<len2){
             arr[index++]=second[in2++];
         }
         delete [] first;
         delete [] second;
         
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
         if(l>=r){
             return;
         }
         int m=(l+r)/2;
         mergeSort(arr,l,m);
         mergeSort(arr,m+1,r);
         merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.



// } Driver Code Ends

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