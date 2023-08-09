class Solution {
public:
    
    bool isPos(vector<int>& nums, int p, int mindist){
        int cnt=0;
        // int last=nums[0];
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            
            if(abs(nums[i+1]-nums[i])<=mindist){
                cnt++;
                i++;
                // last=nums[i];
            }
            
            if(cnt>=p){
                return true;
            }
        }
        
        return false;
    }

int minimizeMax(vector<int> &nums, int p)
{   

    sort(nums.begin(),nums.end());
    int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        
        int ans=-1;
        while(low < high){
            int mid=(low+high)/2;
            
            if(isPos(nums,p,mid)){// mid ->representing the min distance 
                high=mid;
            }else{
                low=mid+1;
            }
        }
        
        return low;
}
   
};