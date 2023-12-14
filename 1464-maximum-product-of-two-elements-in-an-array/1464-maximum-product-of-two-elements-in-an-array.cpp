class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        
        int maxi1=0; // 1
        int maxi2=0;//1
        
        for(int i=0;i<n;i++){ 
            int val=nums[i];
            
            int old=maxi1; //1 
            if(val >= maxi1){
                maxi2=maxi1;
                maxi1=val; //5 
                
                
            }else if(val >=maxi2){
                
                    maxi2=val; //1
                }
            
            
            
            
            
            
          
            
        }
        
        return (maxi1-1)*(maxi2-1);
    }
};