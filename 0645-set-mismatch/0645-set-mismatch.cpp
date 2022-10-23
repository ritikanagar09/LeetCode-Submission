class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mpp;
        int n=nums.size();
        
        vector<int>v(n,-1);//assume koi nhi h
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            v[nums[i]-1]=1;
        }
        
        
        vector<int>ans;
        
        for(auto i:mpp){
            if(i.second==2){
                ans.push_back(i.first);
            }
        }
        
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                ans.push_back(i+1);
            }
        }
        
        //sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};