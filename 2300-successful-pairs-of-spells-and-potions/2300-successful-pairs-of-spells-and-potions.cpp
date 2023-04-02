class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long n=spells.size();
        long long m=potions.size();
        vector<int>ans;
        
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<n;i++){
            // int cnt=0;
            // int a=spells[i];
            long long low=0;
            long long end=m-1;;
            
            while(low<=end){
                int mid=(low+end)/2;
                long long pr=(long long) ((long long)potions[mid]*(long long)spells[i]);
                
                if(pr>=success){
                    end=mid-1;
                }else{
                    low=mid+1;
                }
            }
            // cout<<low<<endl;
            ans.push_back(m-low);
        }
        
        
        return ans;
    }
};