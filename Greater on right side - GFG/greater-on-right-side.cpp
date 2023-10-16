//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
	    int maxi=INT_MIN;
	    for(int i=n-1;i>=0;i--){
	        if(maxi==INT_MIN){
	            maxi=max(maxi,arr[i]);
	            arr[i]=-1;
	        }
	        else{
	            int v=arr[i];
	            arr[i]=maxi;
	            
	            maxi=max(maxi,v);
	            
	        }
	    }
	}


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.nextGreatest(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends