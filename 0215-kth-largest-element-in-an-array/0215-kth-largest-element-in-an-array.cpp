class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //  int n=nums.size();
    //   int arr[k];
    //   int max=INT_MIN;
    //   int max2=INT_MIN+3;
      
    //   for(int i=0;i<n;i++){
    //       if(max<=nums[i]){
    //           max=nums[i];
    //           a[0]=max;
    //       }
    //   }

    //=========================================
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // return nums[n-k];
    //======================================


    priority_queue<int>heap(begin(nums),end(nums));
    for(int i=0;i<k-1;i++){
        heap.pop();
    }
    return heap.top();
    }
};