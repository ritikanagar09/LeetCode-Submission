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
        
        
            int low=0;
            int high=1;// sabse choti window se start krvana hai 
            long long int maxf=1;
            
            while(high < n){ // target ele is low 
                long long int window=high-low+1;// 13 is included
                int pointer=-1;
                long long int exp_sum=window*nums[high];
                long long int curr_sum=presum[high]-presum[low]+nums[low];// if include start from i 
                // if excudes start from i-1

                long long int diff=exp_sum-curr_sum;

                if(diff <= k){
                    pointer=low;
                }else{
                    low++;// window is not valid for this case eg 1 is not valid for 8
                }
                
                // cout<<"//"<<endl;
                // cout<<low<<" "<<high<<endl;
                
                if(pointer != -1){ 
                    long long int range=high-pointer+1;
            
                    maxf=max(maxf,range);
                    high++;
                }
                
                
            }
            
            
            
            
     
        
        return maxf;
            
            
            

        
        
    }
};