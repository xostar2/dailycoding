class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>>v1;
        
        vector<int>v2;
         v2.push_back(1);
                  
        v1.push_back(v2);
       
        for(int i=1;i<num;i++){
            vector<int>v3;
            v3.push_back(1);
        
            for(int j=1;j<i;j++){
                
            v3.push_back( v1[i-1][j-1]+v1[i-1][j]);
                
            }
            
            v3.push_back(1);  
            v1.push_back(v3);
 
        }
        return v1;
    }
};