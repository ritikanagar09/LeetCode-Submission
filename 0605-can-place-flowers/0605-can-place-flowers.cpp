class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int N=nums.size();
        
        if(n==0){
            return true;
        }
        
        if(N==1 ){
            if(nums[0]==0){
                return  true;
            }
            else {
                return false;
            }
        }
        
        for(int i=0;i<N;i++){
            
            if(nums[i]==0){
                
                if((i-1>=0 && nums[i-1]!=1) && (i+1<N && nums[i+1]!=1)){
                    nums[i]=1;
                    n--;
                }else if(i==0){
                    if(nums[i]==0 && (i+1<N && nums[i+1]==0)){
                        n--;
                        nums[i]=1;
                    }
                }else if(i==N-1){
                    if(nums[i]==0 && (i-1 >0 && nums[i-1]==0)){
                        n--;
                        nums[i]=1;
                    }
                }
                 
            }
            
            cout<<n<<endl;
            if(n==0){
                return true;
            }
        }
        
        
        
        return false;
    }
};