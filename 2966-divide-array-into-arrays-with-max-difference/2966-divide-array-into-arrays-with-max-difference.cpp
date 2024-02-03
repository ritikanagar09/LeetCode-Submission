class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        
        int n=nums.size();
        vector<vector<int>>ans;
        if(n %3 !=0){
            
            return ans;
        }
        
        // 1,1,3,3,4,5,7,8,9
        
        // 1,2,3,3,3,7
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            
            int dif1=abs(a-b);
            int dif2=abs(b-c);
            int dif3=abs(a-c);
            if(dif1 <= k && dif2 <= k && dif3 <=k){
                vector<int>v={a,b,c};
                ans.push_back(v);
            }else{
                ans={};
                break;
                
            }
        }
        
        return ans;
    }
};