class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        
        for(auto it:nums){
            mpp[it]++;
        }
        
        int maxi=-1;
        
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        
        int cnt=0;
        
        for(auto it:mpp){
            if(maxi==it.second){
                cnt+=it.second;
            }
        }
        
        return cnt;
    }
};