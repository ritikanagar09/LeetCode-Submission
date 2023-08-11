class Solution {
public:
    int mod=1e9+7;
    long long solve(int cnt_uniq, int cnt_goal, int n, int k,vector<vector<int>>&dp){
        
        if(cnt_uniq==0 && cnt_goal==0){
            return 1LL;
        }
        
        if(cnt_uniq==0 || cnt_goal==0){
            return 0LL;
        }
        
        if(dp[cnt_uniq][cnt_goal] !=-1){
            return dp[cnt_uniq][cnt_goal];
        }
        
        //PLAYING NEW SONG
        // avaialbe kitne unique elem bache h ..kuch toh pehle hi humne use kar liye honage naa 
        
        long long pick = (solve(cnt_uniq-1, cnt_goal-1,n,k,dp)*(n-cnt_uniq+1))%mod; 
        
        
        
        
        //REPLAYING OLD SONG
        // now we are playing already played songs 
        // we are not playing any new song 
        // cnt_uniq -k -> availabe uniq elem me se k hata do kyunki vo beech me aaye honge 
        
        
        long long notpick=0LL;
        if(cnt_uniq > k)
            notpick=(solve(cnt_uniq, cnt_goal-1,n,k,dp)*(cnt_uniq-k))%mod; 
        
        return dp[cnt_uniq][cnt_goal]=(pick+notpick)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        
        return solve(n,goal,n,k,dp);
    }
};