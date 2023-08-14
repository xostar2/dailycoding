//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=arr[i];
    }
    sort(a,a+n);
    int m=n-1;
    for(int i=1;i<n;i=i+2){
        arr[i]=a[m--];
     }
     m=0;
    for(int i=0;i<n;i=i+2){
        arr[i]=a[m++];
    }
    int sum=0;
    for(int i=1;i<n;i++){
        sum+=abs(arr[i]-arr[i-1]);
    }
    sum=sum+abs(arr[0]-arr[n-1]);
    
    return sum;
}