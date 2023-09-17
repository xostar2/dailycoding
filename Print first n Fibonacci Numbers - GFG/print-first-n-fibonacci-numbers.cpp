//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.

// meyashjain
// 7 days ago

// C++ Solution using Dynamic Programming:

// Approach 1: Top-Down approach

// Uses Recursion and Memoization (TC: O(n) , SC: O(n))

long long printF(int n,vector<long long>&dp){
        
        if(n==1||n==0){
            
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = printF(n-1,dp) + printF(n-2,dp);
        return dp[n];
    }
    vector<long long> printFibb(int n) 
    {
        
        vector<long long>dp(n+1,-1);
        vector<long long> ans;
        for(int i=0;i<n;i++){
            ans.push_back(printF(i,dp));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends