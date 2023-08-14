//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    vector<int>arr(256,0);
	    int n=str.size();
	    string ans="";
	    for(int i=0;i<n;i++){
	        int x=str[i];
	        if(arr[x]<1){
	            ans=ans+str[i];
	        }
	        arr[x]++;
	    }
	    
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends