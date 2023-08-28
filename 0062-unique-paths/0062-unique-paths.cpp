class Solution {
public:
    // int check(int m,int n,int i,int j){
    //     if(i==m-1 && j==n-1)return 1;
    //     if(i>m-1 || j>n-1)return 0;
    //     return check( m, n, i+1, j)+check( m, n, i, j+1);
    // }
    int checkDP(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i==m-1 &&j==n-1)return 1;
        if(i>m-1 || j>n-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=checkDP( m, n, i+1, j,dp)+checkDP( m, n, i, j+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return checkDP( m, n, 0, 0,dp);
    }
};