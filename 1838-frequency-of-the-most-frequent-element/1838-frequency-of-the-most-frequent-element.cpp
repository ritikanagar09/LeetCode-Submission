class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        
        sort(nums.begin(), nums.end());
         
        // create a psum array 
        
        vector<long long int>presum(n,0);
        presum[0]=nums[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        
        
        
        
        long long int maxf=1;
        for(int i=n-1;i>=0;i--){
            // int f=1;
            int nk=k;
            
            
            int low=0;
            int high=i;
            int pointer=-1;
            while(low <= high){
                long long int mid=(low+high)/2; // target value
                long long int window=i-mid+1;// 13 is included

                long long int exp_sum=window*nums[i];
                long long int curr_sum=presum[i] -presum[mid]+nums[mid];// if include start from i 
                // if excudes start from i-1

                long long int diff=exp_sum-curr_sum;

                if(diff <= k){
                    pointer=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            
            
            long long int range=i-pointer+1;
            
            maxf=max(maxf,range);
            
            
        }
        
        
        return maxf;
            
            
            

        
        
    }
};