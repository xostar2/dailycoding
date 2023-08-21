//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool check(vector<vector<int>>&matrix ,int i,int j,int n,int m){
        
        if(i>=0 and j>=0 and i<n and j<m and matrix[i][j]==0){
            return true;     
        }
        return false;
    }

    int Count(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            
            q.pop();
            int zero=0;
            for(int l=-1;l<=1;l++){
                for(int k=-1;k<=1;k++){
                    int index1=row+l;
                    int index2=col+k;
                    //if(index1==row and index2==col)continue;
                    if(check(matrix,index1,index2,n,m)){
                        zero++;
                    }
              
                } 
            } 
            if(zero!=0 and zero%2==0){
                ans++;
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends