//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string arr, int k) 
    {
        // your code here
        int n=arr.size();
        int ans=INT_MIN;
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        
        while(j<n)
        {
            mp[arr[j]]++;
            if(mp.size()<k)
                j++;
            else
            if(mp.size()==k)
            {
                ans=max(ans,j-i+1);
                j++;
            }
            else
            if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0)
                        mp.erase(arr[i]);
                    i++;
                }
                j++;
            }
        }
        if(ans==INT_MIN)
            return -1;
        else
            return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends