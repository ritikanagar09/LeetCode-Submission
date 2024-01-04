class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        
        map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(auto it: mpp){
            int cnt=it.second;
            if(cnt==1){
                return -1;
            }
            
            if(cnt % 3==0){
                ans+= cnt/3;
            }else {
                ans+= cnt/3+1;
            }
            
            
            
        }
        
        return ans;
        
        
        //now kaam shuru 
        
        
    }
};