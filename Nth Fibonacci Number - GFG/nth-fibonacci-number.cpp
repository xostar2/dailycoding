//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int mod=1e9+7;
class Solution {
  public:
    int nth(int n,vector<int>&dp){
        
        for(int i=2;i<=n;i++)
            {
                dp[i]=(dp[i-1]+dp[i-2])%mod;
               // cout<<dp[i]<<" ";
            }
        return dp[n]%mod;
    }
  
    int nthFibonacci(int n){
        
        vector<int>dp(n+1,0);
        dp[1]=1;
        if(n==1)return 0;
        if(n==2)return 1;
        return nth(n,dp)%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends