class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int t=queries[i];
            int sum=0;
            int len=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                
                if(sum<=t){
                    len++;
                }else{
                    sum-=nums[i];
                }
            }
            ans.push_back(len);
        }
        
        return ans;
    }
};