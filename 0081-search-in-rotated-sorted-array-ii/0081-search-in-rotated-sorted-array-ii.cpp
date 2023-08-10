class Solution {
public:
    bool search(vector<int>& A, int key) {
         
        

        int l=0;
        int h=A.size()-1;
        while(l<=h){
            if(A[l]==key || A[h]==key){
                return true;
            }
            else {
                l++;
                h--;
            }
        }
        return false;
        
    }
};