//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int nums[], int N) {
        // Your code here
    
        vector<int>ans;
        int n=N+2;
        for(int i=0;i<n;i++){
            
            int index=abs(nums[i])-1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }
            else{
                ans.push_back(index+1);
            }
        }
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends