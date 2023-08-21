class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string A=s;
        A=A+s;
        int n=A.size();
        A=A.substr(1,n-2);
        if(A.find(s)!=string::npos){
            return true;
        }
        return false;
    }
};