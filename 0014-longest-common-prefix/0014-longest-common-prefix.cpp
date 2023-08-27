class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //sorting method
        int x=strs.size();
        if(x==0){
            return ""; 
        }
        if(x==1){
            return strs[0];
        }
        sort(strs.begin(),strs.end());
        int e=min(strs[0].size(),strs[x-1].size());
        string l1=strs[0];
        string l2=strs[x-1];
        int i=0;
        while(i<e &&l1[i]==l2[i]){
            ++i;
        }
        string ans=l1.substr(0,i);
        return ans;
    }
};