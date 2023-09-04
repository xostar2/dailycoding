//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(int start,int end,int n, int m, vector<vector<char>>& mat,vector<vector<int>>&vis){
        
        if(start>=0 and end>=0 and start<n and end<m and mat[start][end]=='O' and !vis[start][end]){
            return true;
        }
        return false;
    }

    void dfs(int start,int end,int n, int m, vector<vector<char>>& mat,vector<vector<int>>&vis){
        
        vis[start][end]=1;
        
        int arr1[4]={-1,1,0,0};
        int arr2[4]={0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int x1=start+arr1[i];
            int x2=end+arr2[i];
            
            if(check(x1,x2,n,m,mat,vis)){
                dfs(x1,x2,n,m,mat,vis);
            }
        }
        
    }


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' and !vis[i][0]){
                dfs(i,0,n,m,mat,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O' and !vis[i][m-1]){
                dfs(i,m-1,n,m,mat,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='O' and !vis[n-1][i]){
                dfs(n-1,i,n,m,mat,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O' and !vis[0][i]){
                dfs(0,i,n,m,mat,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and !vis[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        
        
        return mat;
        
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends