class Solution {
public:
    vector<int> countBits(int n) {
        vector<int >arr(n+1,0);
        arr[0]=0;
        int i=1;
        while(i<=n){
            arr[i]=arr[i&i-1]+1;
            i++;
        }
        return arr;
    }
};