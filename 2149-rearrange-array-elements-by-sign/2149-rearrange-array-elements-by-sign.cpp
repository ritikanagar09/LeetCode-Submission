class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int indx=0;
        int indx1=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 0){
                ans[indx]=nums[i];
                indx+=2;
            }else{
                ans[indx1]=nums[i];
                indx1+=2;
            }
        }
        
        return ans;
    }
};