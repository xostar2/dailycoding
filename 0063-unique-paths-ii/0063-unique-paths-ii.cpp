class Solution {
public:

    int ans(vector<vector<int>>& obstacle,int row,int column,int index1,int index2,vector<vector<int>>&dp){
            if(index1==row-1 && index2==column-1 &&obstacle[index1][index2]!=1 )return 1;
            if(index1>row-1 || index2>column-1)return 0;
            if(obstacle[index1][index2]==1)return 0;
            if(dp[index1][index2]!=-1)return dp[index1][index2];
            return dp[index1][index2]=ans(obstacle,row,column,index1+1,index2,dp)+ans(obstacle,row,column,index1,index2+1,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int row=obstacle.size();
        int column=obstacle[0].size();
        vector<vector<int>>dp(row+1,vector<int>(column+1,-1));
        return ans(obstacle,row,column,0,0,dp);
    }
};