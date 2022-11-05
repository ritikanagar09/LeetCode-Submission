class Solution {
    unordered_set<string>mp;// isme hi store karvaayenge sari strings ko jo words vector me hai
                               
    vector<string>ans;// final answer store karna k liye 
    
    int maxi=0;
    int m;
    int n;
    
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>&visited, string &s){
        if(i<0 || j<0 || i>=n || j>=m)return;
        
        if(visited[i][j] || s.length()>=maxi)return;
        
        s.push_back(board[i][j]);
        
        //pucho kya ye jo word bna h 's'
        //kya ye map ke ander h
        
        
        if(mp.count(s)){
            ans.push_back(s);
            mp.erase(s);
        }
        
        //pehle toh bol do ye cell visit ho gya h
        
        visited[i][j]=true;
        
        // 4 call maar do -> upar niche left right ki
        
        dfs(i+1,j,board, visited,s);
        dfs(i,j+1,board, visited,s);
        dfs(i-1,j,board, visited,s);
        dfs(i,j-1,board, visited,s);
        
        //bactracking 
        // matlab pehle stated jo thi ..usme vaapsa chle jao
        visited[i][j]=false;
        s.pop_back();
        
        
        
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //   ->hume pta hai dfs har ek character par jayega ...jo ki uska kaam hai ..vo har ek node par jata hai 
        // ->dfs will generate all the possible strings with starting of each char of string 
        // -> matlab har ek char se shuru hone wali saari string generate kar dega 
        // -> jo ki uska kaam hai ..har ek node par jana 
        // ->ab bss ye dekhna hai ki ahar koi generated string milti hai jo ki given words me hai ..use include kar lo
        
        n=board.size();
        m=board[0].size();
        
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        
        
        // jo map bnaya tha ..usme daaldo sare words
        for(auto w: words){
            mp.insert(w);
            maxi=max(maxi, (int)w.length());
        }
        
        string s="";
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(i,j,board, visited, s );
            }
        }
        
        return ans;
    }
};