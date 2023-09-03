//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
       
       int ifpt=0;
       for(int i=N-1;i>=0;i--){
           if(arr[i]>arr[i-1]){
              ifpt=i;
              break;
           }
       }
       
        if(ifpt==0){
            sort(arr.begin(),arr.end());
        }
        else
         {
             //int min=INT_MAX;
             int to_swap=arr[ifpt-1];
             for(int j=ifpt;j<N;j++){
                 if(arr[j]-to_swap>0 ){
                     swap(arr[j],arr[ifpt-1]);
                 }
             }
             sort(arr.begin()+ifpt,arr.end());
             
             
         }       
       return arr;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends