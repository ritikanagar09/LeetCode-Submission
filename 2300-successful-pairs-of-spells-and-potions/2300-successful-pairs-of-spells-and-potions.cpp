class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long k) {
        int n=s.size();
        int m=p.size();
        
        sort(p.begin(),p.end());
        
        
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int num=s[i];
            
            int l=0;
            int h=m-1;
            
            while(l<=h){
                int mid=(l+h)/2;
                
                long long int prod=(long long)num* (long long)p[mid];
                if(prod >=k){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
            
            int size=m-l;
            ans[i]=size;
            
        }
        
        return ans;
    }
};