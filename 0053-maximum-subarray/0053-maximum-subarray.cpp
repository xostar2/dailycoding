class Solution {
public:
    int maxSubArray(vector<int>& a ) {
        int size=a.size();
         int x=0;
         int y=-99999;
        if(size==1){
            return a[0];
        }
        for(int i=0;i<size;i++){
            x=max(x+a[i],a[i]);
            if(x>y){
                y=x;
            }
        }
        return y;
    }
};