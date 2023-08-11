class Solution {
public:
    int solve(vector<int>&coins,int amount,int n,vector<vector<int>>&dp){
        
        if(n==0){
            if(amount%coins[0]==0)return 1;
            else return 0;
        }
        if(dp[n][amount]!=-1)return dp[n][amount];
        int nottake=solve(coins,amount,n-1,dp);
        int take=0;
        if(coins[n]<=amount){
            take=solve(coins,amount-coins[n],n,dp);
        }
        return dp[n][amount]=take+nottake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(coins,amount,n-1,dp);
    }
};