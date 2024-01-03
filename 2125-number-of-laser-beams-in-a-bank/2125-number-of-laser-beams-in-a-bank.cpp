class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        
        int prev=0;
        for(int i=0;i<m;i++){
            if(bank[0][i]=='1'){
                prev++;
            }
        }
        
        cout<<prev<<endl;
        
        int cnt=0;
        
        for(int i=1;i<n;i++){
            int curr=0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1'){
                    curr++;
                }
            }
            
            int ans=curr*prev;
            // cout<<ans<<" "<<curr<<endl;
            cnt+=ans;
            if(curr != 0){
                prev=curr;
            }
            
        }
        
        
        return cnt;
    }
};