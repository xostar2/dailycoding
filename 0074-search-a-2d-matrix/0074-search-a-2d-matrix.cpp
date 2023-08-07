class Solution {
public:
    
    bool solve(vector<vector<int>>& matrix, int target,int startrow,int endrow,int startcolumn,int endcolumn,int n,int m){
                
        while(startrow<=endrow){
                int midrow=(endrow+startrow)/2;
                if(matrix[midrow][startcolumn]==target||matrix[midrow][endcolumn]==target )return true;
                
                else if(matrix[midrow][endcolumn]>target  &&  matrix[midrow][startcolumn]<target) {
                    
                    while(startcolumn<=endcolumn){
                        int midcolumn=(endcolumn+startcolumn)/2;
                        
                        if(matrix[midrow][midcolumn]==target){
                            return true;
                        }
                        else if(matrix[midrow][midcolumn]<target){
                            startcolumn=midcolumn+1;
                            
                        }
                        else if( matrix[midrow][midcolumn]>target){
                            endcolumn=midcolumn-1;
                        }
                    }
                    return false;
                
                }
                else if(matrix[midrow][startcolumn]>target){
                    endrow=midrow-1;
                }
                else if(matrix[midrow][endcolumn]<target){
                    startrow=midrow+1;
                }
                    
                    
                
        }
        
            
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        return solve(matrix,target,0,n-1,0,m-1,n,m);
    }
};