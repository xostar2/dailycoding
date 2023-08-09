//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int int_common(string &s1,string &s2,int index1,int index2,vector<vector<int>>&dp){
        
        if(index1<0 ||index2<0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(s1[index1]==s2[index2]) return dp[index1][index2]= 1+int_common(s1,s2,index1-1,index2-1,dp);
        return dp[index1][index2]=max(int_common(s1,s2,index1,index2-1,dp),int_common(s1,s2,index1-1,index2,dp));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
         vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return int_common(s1,s2,x,y,dp)-1;
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends