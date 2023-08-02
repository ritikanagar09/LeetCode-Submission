class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>mpp;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            mpp[nums[i]]=1;
        }
        
        for(int i=1;i<=maxi;i++){
            if(mpp.find(i)==mpp.end()){
                return i;
            }
        }
        
        if(maxi < 0){
            return 1;
        }
        
        return maxi+1;
    }
};