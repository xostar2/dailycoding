class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
           
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
       
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int arr1[4]={1,-1,0,0};
        int arr2[4]={0,0,-1,1};
        while(!q.empty()){
            
            int first=q.front().first.first;
            int second=q.front().first.second;
            int d=q.front().second;
            
            dist[first][second]=d;
            q.pop();
            for(int i=0;i<4;i++){
                int a=arr1[i]+first;
                int b=arr2[i]+second;
                
                if(a>=0 and b>=0 and a<n and b<m and vis[a][b]==0){
                    q.push({{a,b},d+1});
                    vis[a][b]=1;
                }
            }
        }
        return dist;
    }
};