class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n ; i++){
            if(nums[i]==1){
                nums[i]= -1;
            }
            else{
                nums[i]=1;
            }
        }
        map<int,int>mp;
        mp[0]=1;
        int sum =0;
        int ans =0;
        for(int i =0; i<n ; i++){
            sum += nums[i];
            if(sum ==0){
               ans = i+1;
            }
            if(mp.find(sum)!= mp.end()){
                int k = i - mp[sum];
                ans = max(ans,k);
            }
            else{
            mp[sum]=i;
            }

        }
        return ans;
        
    }
};