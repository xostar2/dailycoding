//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int perfectans(int arr[], int n, int sum,vector<vector<int>>&dp){
	    
	     if(n==0){
	        if(sum==0){
	            if(arr[0]==0) return 2;
	            return 1;
	        }
	        else{
	            if(arr[0]==sum) return 1;
	            return 0;
	        }
	    }
	    if(dp[n][sum]!=-1)return dp[n][sum];
	    int nottake=perfectans(arr,n-1,sum,dp);
	    int take=0;
	    if(arr[n]<=sum) take=perfectans(arr,n-1,(sum-arr[n]),dp);
	    
	    return dp[n][sum]=(take+nottake)%1000000007;
	    
	    
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return perfectans(arr,n-1,sum,dp);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends