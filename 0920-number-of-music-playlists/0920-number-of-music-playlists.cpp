class Solution {
public:
    int MOD = 1e9 + 7;
    long long goFind(int n, int goal, int k, vector<vector<int>> &dp) {
        if(n == 0 && goal == 0) {
            return 1;
        }
        if(n == 0 || goal == 0) return 0;
        if(dp[n][goal] != -1) {
            return dp[n][goal];
        }

        //We are taking the song, so we can have n possibility for the current pick.
        //On the next next iterations the songs will get reduced to n-1, n-2, ..., 1
        long long total = goFind(n-1, goal-1, k, dp) * 1ll * (n);

        //Now we try to pick some other song from the given list and try to pull out the
        //combinations possible, so for it to be done what are the possible answers?
        //For this let us take a small example. Assume we have -
        // Songs in the playlist s1, s2, s3, s4, _ and k = 2, so what all options we have? so it
        // can't be s3 and s4 for sure now our n=4 (number of used unique songs) which we are 
        // trying to place so it can be s1 or s2 so we choose (n-k) songs here...
        if(n>k) {
            total += goFind(n, goal-1, k, dp) * 1ll * (n-k);
        }
        return dp[n][goal] = total%MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1, vector<int>(goal+1, -1));
        return goFind(n, goal, k, dp);
    }
};