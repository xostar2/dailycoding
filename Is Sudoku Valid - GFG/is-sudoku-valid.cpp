//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> arr){
            int gridrow[9][9]={0};
            int gridcolumn[9][9]={0};
            int gridbox[9][9]={0};
            
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(arr[i][j]!=0){
                        int number=i/3*3+j/3;
                        if(gridrow[j][arr[i][j]-1] || gridcolumn[i][arr[i][j]-1] || gridbox[number][arr[i][j]-1] ){
                            return 0;
                        }
                        gridrow[j][arr[i][j]-1]++;
                        gridcolumn[i][arr[i][j]-1]++;
                        gridbox[number][arr[i][j]-1]++;
                        
                    }
                }
            }
            return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends