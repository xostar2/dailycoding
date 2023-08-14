//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xxory=0;
        vector<int>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            xxory=xxory^nums[i];
        }
        
        int f=0;
        int e=0;
        
        int x=xxory & ~(xxory-1);
        
        for(int i=0;i<n;i++){
            if((nums[i] & x)==0){
                f=f^nums[i];
            }
            else{
                e=e^nums[i];
            }
        }
        
        if(f<e){
        ans.push_back(f);
        ans.push_back(e);
        }else {
            ans.push_back(e);
        ans.push_back(f);   
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends