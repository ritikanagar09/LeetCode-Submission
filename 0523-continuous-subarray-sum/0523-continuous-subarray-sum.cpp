class Solution {
public:
//     [0-5]->modulo
//     [0-2]->modulo
//     [3-5]->0
        
//     {s,2}
    bool checkSubarraySum(vector<int>& nums, int k) {
//         [23,2,4,6,7]
//         [23,25,29,35,42];
//         0   1.  2  3  4
            
//         {5,0}  
//         {
//           i=2-0>=2  
//         }
//         k=6
        
//         25
        unordered_map<int,int>mp;//sum ka modulous,index
        
        mp[0]=-1;
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        
            if(sum%k==0 && i>=1)
            {
               return true;
            }
            
            if(mp.find(sum%k)!=mp.end())
            {
                
               if(i-mp[sum%k]>=2)//length
                {
                    return true;
                }
            }
            else
             mp[sum%k]=i;
        }
        
        return false;
    }
};