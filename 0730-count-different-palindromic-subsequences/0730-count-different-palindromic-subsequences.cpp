class Solution {
public:
    int m=1e9+7;
    /*You are required to complete below method */
        long long int  find(string s1,int i,int j,vector<vector<long long int>> &dp){
        if(i==j){
            return 1;
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s1[j]){
            return dp[i][j]=1+(find(s1,i+1,j,dp)%m+find(s1,i,j-1,dp)%m)%m;
        }else{
            return dp[i][j]=((find(s1,i+1,j,dp)%m+find(s1,i,j-1,dp)%m-find(s1,i+1,j-1,dp)%m+m)%m)%m;
        }
    }
    
int countPalindromicSubsequences(string s) {
         int mod = pow( 10 , 9 ) + 7 ;
    int n = s.size() ;
    
    long long int dp[n][n] ;
    
    int prev[n] , next[n] ;
    
    unordered_map< char , int >mp ;
    
    memset( dp , 0 , sizeof(dp) );
    
    for( int i = 0 ; i < s.size() ; i++ )
    {
        if( mp.find(s[i]) == mp.end())
        {
            prev[i] = -1 ;
        }
        else{
            prev[i] = mp[s[i]] ;
        }
        
        mp[s[i]] = i ;
    }
    
    
    mp.clear() ;
    
    for( int i = s.size() - 1  ; i >= 0  ; i-- )
    {
        if( mp.find(s[i]) == mp.end())
        {
            next[i] = -1 ;
        }
        else{
            next[i] = mp[s[i]] ;
        }
        
        mp[s[i]] = i ;
    }
    
    
    for( int g = 0 ; g < n ; g++ )
    {
        for( int i = 0 , j = g ; j < n ; i++ , j++ )
        {
            if( g == 0 )
            {
                dp[i][j] = 1 ;
            }
            else if( g == 1 )
            {
                dp[i][j] = 2 ; 
            }
            else{
                
                if( s[i] != s[j] )
                {
                    dp[i][j] = ( ( dp[i+1][j] + dp[i][j-1] )%mod - dp[i+1][j-1] )%mod  ;
                }
                else
                {
                   int nx = next[i] ;
                   int p =  prev[j] ;
                    
                   if( nx > p )
                {
                    dp[i][j] = ( (2*dp[i+1][j-1])%mod  + 2 )%mod ;
                }
                else if( nx < p )
                {
                    dp[i][j] = ( (2*dp[i+1][j-1])%mod - dp[nx+1][p-1])%mod  ;
                }
                else{
                    
                    
                    dp[i][j] = ( (2*dp[i+1][j-1])%mod + 1 )%mod ;
                }
                
                    
                    
                }
               
            }
            
             if(dp[i][j] < 0){
                //Avoiding mod of negatives
                dp[i][j] = (dp[i][j] + mod)%mod;
            }
        }
    }
    
       
    
    
    return dp[0][n-1]%mod  ;
    }
};