class Solution {
public:
    
    bool solve(int ind, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(ind>=n) return true;

        if(dp[ind] != -1) return dp[ind];

        bool ans = false;
        // Rule 1
        if(ind+1 < n &&nums[ind] == nums[ind+1]){
            ans = solve(ind+2, nums, dp);
        }
        if(ans == true) return true;
        // Rule 2
        if(ind+2 < n && (nums[ind] == nums[ind+1]) && (nums[ind+1] == nums[ind+2])){
            ans = solve(ind+3, nums, dp);
        }
        if(ans == true) return true;
        // Rule 3
        if(ind+2 < n && (nums[ind+1] - nums[ind] == 1) && (nums[ind+2] - nums[ind+1] == 1)){
            ans = solve(ind+3, nums, dp);
        }
        
        return dp[ind] = ans;

    }
    
    
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};