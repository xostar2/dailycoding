//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

       bool check(vector<vector<char>>& board,vector<vector<int>>&vis,int start,int end,int n,int m){
       if(start>=0 && end>=0 && end<m && start<n && board[start][end]=='O' && !vis[start][end])return true;

       return false;
   }



    void dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int start,int end,int n,int m){

        vis[start][end]=1;
        int arr1[]={1,-1,0,0};
        int arr2[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int n1=start+arr1[i];
            int n2=end +arr2[i];
            if(check(board,vis,n1,n2,n,m)){
                dfs(board,vis,n1,n2,n,m);
            }
        }

    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X')count++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(board,vis,i,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(board,vis,0,i,n,m);
            }
        }
         for(int i=0;i<m;i++){
            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(board,vis,n-1,i,n,m);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    return board;
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