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
             while(mpp.find(nums[j]) != mpp.end()){
                    mpp.erase(nums[i]);
                    len-=nums[i];
                    i++;
                 }
            
            
                len+=nums[j];
                mpp[nums[j]]=1;
                j++;
            
                
                maxi=max(maxi,len);
               
                
            
            // cout<<i<<" "<<j<<endl;
        }
            
        maxi=max(maxi,len);
        
        return maxi;
    }
};