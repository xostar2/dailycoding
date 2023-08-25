class Solution {
public:
    int n,m,N;
    int dp[101][101];
    bool solution (int i,int j,string s1, string s2, string s3){
        
        if(i==n and j==m and i+j==N)return true;
        if(i+j>=N)return false;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        bool result=false;
        
        if(s1[i]==s3[i+j]){
            result=solution(i+1,j,s1,s2,s3);
        }
        
        if(result==true){
            return dp[i][j]=result;
        }
        
        if(s2[j]==s3[i+j]){
            result=solution(i,j+1,s1,s2,s3);
        }
        
        return dp[i][j]=result;
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        N=s3.size();
        
        memset(dp,-1,sizeof(dp));
        return solution(0,0,s1,s2,s3);
    }
};