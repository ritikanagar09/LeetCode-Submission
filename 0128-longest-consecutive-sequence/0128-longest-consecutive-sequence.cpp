class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        int cnt=1;
        int maxcnt=0;
        for(int i=0;i<n;i++){
            
            if(i>0 && nums[i]==nums[i-1]+1){
                cnt++;
            }else if(i>0 && nums[i]==nums[i-1]){
                continue;
            }else{
            
                maxcnt=max(cnt,maxcnt);
                cnt=1;
            }
        }
        maxcnt=max(cnt,maxcnt);
        return maxcnt;
    }
};