class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start=0;
        int end=0;
        int n=nums.size();
        vector<string>hold;
        if(n==0)return hold;
        if(n==1)return {to_string(nums[0])};
        while(end<n-1){
            
            if(nums[end]+1==nums[end+1]){
                end++;
            }
            else{
                if(start==end){
                    string s=to_string(nums[start]);
                    hold.push_back(s);
                    end++;
                    start=end;
                }
                else{
                    string a=to_string(nums[start])+"->"+to_string(nums[end]);
                    hold.push_back(a);
                    end++;
                    start=end;
                }                    
            }
            
        }
        
        if(start==end){
            string s=to_string(nums[start]);
                    hold.push_back(s);
        }
        else{
              string a=to_string(nums[start])+"->"+to_string(nums[end]);
                    hold.push_back(a);

        }
        
        return hold;
    }
};