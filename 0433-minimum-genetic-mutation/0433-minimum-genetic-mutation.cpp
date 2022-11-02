class Solution {
public:
    int minMutation(string st, string ed, vector<string>& bank) {
        int n = st.size();
        int m = ed.size();
        int count =0;
        vector<int>ans;
        map<int,vector<string>>mp;
        for(int i =0 ; i<bank.size(); i++){
            string f = bank[i];
            int count=0;
            for(int j =0 ; j< n ; j++){
                if(st[j]!= f[j]){
                    count++;
                }
            }
            mp[count].push_back(f);
        }
        queue<pair<int,string>> q;
        q.push({0,st});
        while(!q.empty() ){
           pair<int,string>f = q.front();
            string z = f.second;
            int t = f.first;
            q.pop();
            for(int i =0 ; i<bank.size(); i++){
                int count =0;
                for(int j =0 ; j<8 ; j++){
                    if(bank[i][j]!= z[j]){
                        count++;
                    }
                }
                if(count==1){
                    int s = t+1;
                    q.push({s,bank[i]});
                    
                    if(bank[i]==ed){
                        ans.push_back(s);
                    }
                    bank[i]= " ";
                }
            }   
        }
        if( ans.size()==0){
            return -1;
        }
        sort(ans.begin(), ans.end());
        return ans[0];
        
    }
};