class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        nums[c++]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[c++]=nums[i];
            }
        }
        return c;
    }
};