class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long mod=1000000007;

        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int high=0;
        
        vector<int>power(n,0);
        power[0]=1;
        
         for(int i=1;i<n;i++)
        {
           power[i]=(power[i-1]*2)%mod;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<=(target/2))
            {
                high=i;
                break;
                
            }
        }
        
        
        long long cnt=0;
     
    
            int l=0,h=n-1;
            
            while(l<=h)
            {
                if(nums[l]+nums[h]<=target)
                {
                   
                    cnt+=power[h-l]%mod;
                    cnt=cnt%mod;
                    l++;
                }
                else
                {
                    h--;
                }
            }
        
        
        return cnt%mod;
    }
};