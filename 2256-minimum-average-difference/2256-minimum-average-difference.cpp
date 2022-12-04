class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        // vector<long long> v;
        
        long long preSum=0;
        long long sum=0;
        // // long long sufSum=0;
        for(auto i: nums){
            sum+=i;
        }
        // long long sum=accumulate(nums.begin(), nums.end(), 0);
        int mn = INT_MAX;
        int idx = 0;
        // cout<<sum<<endl;
        for(long long int i=0 ;i<nums.size();i++){
            preSum+=nums[i];
            
            // sufSum=sum-preSum;
            sum-=nums[i];
           
//             cout<<preSum<<" "<<sufSum<<endl;
            
            
            int diff=0;
            
            
            
            if(i==n-1)
                diff = preSum/(i+1);
            else
                diff = abs((preSum/(i+1)) -(sum/(n-i-1)));
             
            if(diff < mn){
                mn = diff;
                idx = i;
            }
            
           
            // v.push_back(diff);
            
        }
        
        
        return idx;
        
        
        
        
        // v.push_back(sum/n);
       
        
        // long long int ans= *min_element(v.begin(), v.end());
        
//         int mini=INT_MAX;
//         for(long long i=0 ;i<v.size();i++){
//             if(v[i]<mini){
//                 mini=v[i];
//             }
//         }
        
        
        
        
//         for(long long i=0 ;i<v.size();i++){
//             if(mini==v[i])
//                 return i;
//         }
        
//         return 0;
        
        
        
        
        
        
        
        
    }
};