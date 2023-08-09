class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
         solve(board);
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                 if(board[i][j]=='.'){
                        
                     for(char c='1';c<='9';c++){
                         
                         if(isvalid(board,i,j,c)){
                             board[i][j]=c;
                             if(solve(board)==true)
                             {
                                 return true;
                             }
                             else 
                             {
                                 board[i][j]='.';
                             }
                         }
                     }
                     return false; 
                 }  
                                
            }
        }
        return true;
    }
    
    bool isvalid(vector<vector<char>>& board,int row ,int col,char ch){
        
        int n=board.size();
    for(int i=0;i<n;i++){
        // row check
        if(board[row][i]==ch ){
            return false;
        }
        // column check
       else if(board[i][col]==ch ){
            return false;
        }
        // 3*3 matrix check
        else if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch ){
            return false;
        }
    } 
       return true;
    }
            
};