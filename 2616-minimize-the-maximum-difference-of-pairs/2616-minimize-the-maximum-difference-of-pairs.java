class Solution {
        public int minimizeMax(int[] nums, int p) {
                if (p == 0)  return 0;
                        if (nums.length <= 2)  return Math.abs(nums[0] - nums[1]);
                                Arrays.sort(nums);
                                        int right = 0;
                                                int left  = 1_000_000_001;
                                                        for (int i = nums.length - 2; i >= 0; i--) {
                                                                    right = Math.max(right, nums[i + 1] - nums[i]);
                                                                                left  = Math.min(left,  nums[i + 1] - nums[i]);
                                                                                        }
                                                                                                if (left == right)  return left;
                                                                                                        while (left < right) {
                                                                                                                    int mid = left + (right - left) / 2;
                                                                                                                                if (isValid(mid, nums, p)) 
                                                                                                                                                right = mid;
                                                                                                                                                            else 
                                                                                                                                                                            left = mid + 1;
                                                                                                                                                                                    }
                                                                                                                                                                                            return left;
                                                                                                                                                                                                }
                                                                                                                                                                                                    
                                                                                                                                                                                                        
                                                                                                                                                                                                            private boolean isValid(int guess, int[] nums, int p) {
                                                                                                                                                                                                                    int count = 0;
                                                                                                                                                                                                                            for (int i = nums.length - 1; i > 0; i--) {
                                                                                                                                                                                                                                        if (nums[i] - nums[i - 1] <= guess) {
                                                                                                                                                                                                                                                        if (++count >= p)  return true;
                                                                                                                                                                                                                                                                        i--;
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                    return count >= p;
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                    
                                            

}