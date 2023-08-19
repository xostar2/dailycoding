class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0; // Number of total votes for a certain candidate
        int candidate; // tracks what value we are currently on
        
        for (int i =0; i < nums.size(); i++)
        {
            if (vote == 0) // if the vote is 0 (or in other words we haven't had a candidate with enough sequential votes)
                candidate = nums[i]; // we make our new candidate the current value
            
            if(nums[i] == candidate) // we then check if the current value matches our candidate. If it does we add one to their vote tally
                vote++;
            else // otherwise we subtract one
                vote--;
            
        }
        return candidate;
    }
};