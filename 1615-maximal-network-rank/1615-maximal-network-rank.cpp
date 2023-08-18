class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
             
        vector<int>dp(n,0);
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        for(auto & road:roads){
            int u=road[0];
            int v=road[1];
            dp[u]++;
            dp[v]++;
            
            vis[u][v]=true;
            vis[v][u]=true;
        }
        
        int maxrank=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                int i_rank=dp[i];
                int j_rank=dp[j];
                
                int rank=i_rank+j_rank;
                if(vis[i][j]){
                    rank--;
                }
                maxrank=max(maxrank,rank);
            }
        }
        return maxrank;
    }
};