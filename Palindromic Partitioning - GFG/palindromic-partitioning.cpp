//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++





class Solution{

public:

    int t[501][501];

    int ispalindrome(string str,int i,int j)

    {

        

        if(i==j)

        {

            return 1;

        }

        if(i>j)

        {

            return 0;

        }

        while(i<j)

        {

            if(str[i]!=str[j])

            {

                return 0;

            }

            i++;

            j--;

        }

        return 1;

        

        

    }

    int solve(string str,int i,int j)

    {

        int l,r;

        if(i>=j)

        {

            return 0;

        }

        if(t[i][j]!=-1)

        {

            return t[i][j];

        }

        if(ispalindrome(str,i,j))

        {

            return 0;

        }

        int mn=INT_MAX;

        for(int k=i;k<j;k++)

        {

            if(t[i][k]!=-1)

            {

                l=t[i][k];

            }

            else

            {

                l=solve(str,i,k);

                t[i][k]=l;

            }

            if(t[k+1][j]!=-1)

            {

                r=t[k+1][j];

            }

            else

            {

                r=solve(str,k+1,j);

                t[k+1][j]=r;

            }

            int temp=1+l+r;

            if(mn>temp)

            {

                mn=temp;

            }

       

        }

         return t[i][j]=mn;

    }

    

    int palindromicPartition(string str)

    {

        

        memset(t,-1,sizeof(t));

        int l=str.size();

        int i=0;

        int j=l-1;

        return solve(str,i,j);

        

    }

};













// class Solution{
// public:
//     int palindromicPartition(string s)
//     {
//         vector<vector<string>>result;
//         vector<string>path;
//         fun(0,s,path,result);
//         return result.size();
//     }
    
    
//      void fun(int index,string s,vector<string>&path,vector<vector<string>>&result){

//         if(index==s.size()){
//             result.push_back(path);
//             return;
//         }

//         for(int i=index;i<s.size();++i){
//             if(ispalindrom(s,index,i))
//             {
//                 path.push_back(s.substr(index,i-index+1));
//                 fun(i+1,s,path,result);
//                 path.pop_back();
//             }

//         }
//      }
//          bool ispalindrom(string s,int start,int end){
//         while(start<=end){
//             if(s[start++]!=s[end--])return false;
//         }
//         return true;
//         }
    
// };




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends