class Solution {
public:
    int f(int i,int n , int k ,vector<int>& nums){
        if(i>=n && k==0){
            return 1;
        }
        if(i>=n || k<0){
            return 0;
        }
        int pick = f(i+1,n,k-nums[i],nums);
        int npick =f(i+1,n,k,nums);
        return pick + npick;
    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        int n = nums.size();
        int sum =0;
        for(int i =0; i<n ; i++){
            sum+= nums[i];
        }
        int k = sum-tar;
        if(k%2 !=0){
            return 0;
        }
        k = k/2;
        int i =0;
        int ans =f(i,n,k,nums);
        return ans;
    }
};