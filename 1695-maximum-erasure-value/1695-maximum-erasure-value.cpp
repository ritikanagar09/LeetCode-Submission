class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        
        
        int maxi=0;
        int len=0;
        map<int,int>mpp;
        
        int i=0;
        int j=0;
        while(i<n && j<n){
            
            if(mpp.find(nums[j]) == mpp.end()){
                len+=nums[j];
                mpp[nums[j]]=1;
                j++;
            }else{
                
                maxi=max(maxi,len);
                while(mpp.find(nums[j]) != mpp.end()){
                    mpp.erase(nums[i]);
                    len-=nums[i];
                    i++;
                 }
                
            }
            // cout<<i<<" "<<j<<endl;
        }
            
        maxi=max(maxi,len);
        
        return maxi;
    }
};