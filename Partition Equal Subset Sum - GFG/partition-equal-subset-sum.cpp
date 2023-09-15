//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int check(int nums[],int index,int sum,vector<vector<int>>&dp){
      if(sum==0)return 1;
      if(index==0)return (nums[0]==sum);
      if(dp[index][sum]!=-1)return dp[index][sum];
      int nottake=check(nums,index-1,sum,dp);
      int take=0;
      if(sum>=nums[index]){
          take=check(nums,index-1,sum-nums[index],dp);
      }
      return dp[index][sum]= take | nottake;
    }

    int equalPartition(int N, int nums[])
    {
         int sum=0;
       
       
       for(int i=0;i<N;i++){
           sum+=nums[i];
       }
       vector<vector<int>>dp(N,vector<int>(sum/2 +1 ,-1));
       if(sum%2==1)return 0;
       return check(nums,N-1,sum/2,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends