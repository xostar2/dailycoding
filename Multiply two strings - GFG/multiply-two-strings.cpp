//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n1=s1.size();
       int n2=s2.size();
       
       bool s1neg=false;
       bool s2neg=false;
       
       if(s1[0]=='-'){
           
           s1neg=true;
           s1[0]='0';
       }
       if(s2[0]=='-'){
           s2neg=true;
           s2[0]='0';
       }
       
       
       
       string ans(n1+n2,'0');
       
       for(int i=n1-1;i>=0;i--){
           for(int j=n2-1;j>=0;j--){
               int product= (s1[i]-'0')*(s2[j]-'0')+ans[i+j+1]-'0';
               ans[i+j+1]=product%10 + '0';
               ans[i+j]+=product/10;
           }
       }
       
       string a;
       for(int i=0;i<n1+n2;i++){
           if(ans[i]!='0'){
               a=ans.substr(i);
               break;
           }
       }
       
       if(s1neg and s2neg){
           return a;
       }
       if(s1neg){
            a='-'+a;
           return a;
       }
       if(s2neg){
           a='-'+a;
           return a;
       }
       
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends