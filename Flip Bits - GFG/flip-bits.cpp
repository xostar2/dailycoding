//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Using Kadane Alog. : { TC : O(n) and SC : O(1) }

class Solution{
    public:
    
    int kadaneAlgo(int arr[], int n)
    {
        int maxSum = 0, currSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            currSum += (arr[i]==0) ? 1 : -1;
            
            maxSum = max(maxSum,currSum);
            
            if(currSum < 0)
            {
                currSum = 0;
            }
        }
        
        return maxSum;
    }

    int maxOnes(int arr[], int n)
    {
        // Your code goes here
        int totSum = accumulate(arr,arr+n,0);

        return totSum + kadaneAlgo(arr,n);
    }
};



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends