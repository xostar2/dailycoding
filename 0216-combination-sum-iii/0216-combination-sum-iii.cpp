class Solution {
public:
void f(int i,int tar,vector<int>&can,vector<vector<int>>&res,vector<int>&temp,int k){
     if(tar==0){
         if(temp.size()==k)
                res.push_back(temp);
                return;
            } 
        for(int j=i;j<can.size();j++){
            if(j>i && (can[j]==can[j-1])) continue;
            if(can[j]>tar) break;
            temp.push_back(can[j]);
            f(j+1,tar-can[j],can,res,temp,k);
            temp.pop_back();
        }
}
    vector<vector<int>> combinationSum3(int k, int tar) {
        vector<int>can;
        for(int i=0;i<9;i++){
            can.push_back(i+1);
        }
        vector<vector<int>>res;
        vector<int>temp;
        f(0,tar,can,res,temp,k);
        return res;
    }
};


// class Solution {
// public:
    
//     void hold_combo(int index,int k,int n,int sum,vector<int>&ds,vector<vector<int>>&ans,vector<int>g){
        
        
        
//        for(int i=index;i<9;i++){
//         if(ds.size()<=3){
//             ds.push_back(g[index]);
//             sum=sum+g[index];
//         }
//         hold_combo(index+1,k,n,sum,ds,ans,g);
//         sum=sum-g[index];
//        } 
       
        
//        // hold_combo(index+1,k,n,ds,ans,g);    
    
//     }
    
//     vector<vector<int>> combinationSum3(int k, int n) {
//     vector<vector<int>>ans;
//     if(n<2){
//         return ans;
//     }
//     vector<int>ds;
//     int sum=0;
//     vector<int >g={1,2,3,4,5,6,7,8,9};
//     hold_combo(0,k,n,sum,ds,ans,g);

//     return ans;    

//     }
// };