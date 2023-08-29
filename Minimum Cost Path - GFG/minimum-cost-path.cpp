//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 int arr1[4]={1,-1,0,0};
 int arr2[4]={0,0,-1,1};
 typedef pair<int,pair<int,int>> p;
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        
        priority_queue<p,vector<p>,greater<p>>q;
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        dist[0][0]=grid[0][0];
        
        q.push({dist[0][0],{0,0}});
        
        while(!q.empty()){
            
            auto it=q.top();
            q.pop();
            int wt=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            
            for(int i=0;i<4;i++){
                int index1=arr1[i]+row;
                int index2=arr2[i]+col;
                
                if(index1>=0 && index2>=0 && index1<n && index2<n){
                    
                    if(dist[index1][index2]>wt+grid[index1][index2]){
                        dist[index1][index2]=wt+grid[index1][index2];
                        q.push({dist[index1][index2],{index1,index2}});
                    }
                }
            }
            
            
        }
        
        return dist[n-1][n-1];
        
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends