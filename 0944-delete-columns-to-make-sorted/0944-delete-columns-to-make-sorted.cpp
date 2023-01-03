class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        
        int cnt=0;
        
        int i=0;//position 
        while(i<m){
            bool islexo=true;
            char prev=strs[0][i];
            
            for(int j=0;j<n;j++){//saari string ko visit kar 
                char curr=strs[j][i];
                if(prev>curr){
                    islexo=false;
                    break;
                }
                prev=curr;
            }
            
            if(!islexo){
                cnt++;
            }
        
            i++;
        }
        
        
        
        return cnt;
    }
};