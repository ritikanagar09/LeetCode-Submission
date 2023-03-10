class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        int maxi=*max_element(piles.begin(),piles.end());
        // int sum=0;
        // for(auto i:piles){
        //     sum+=i;
        // }
        
       
        
        
        int ans=maxi;
        int low=1;
        int high=maxi;
        while(low<=high){
            int hrs=0;
            int mid=high-(high-low)/2;
            
            for(int i=0;i<n;i++){
                int x=piles[i]/mid;
                int y=piles[i]%mid;
                
                hrs+=x;
                if(y>0){
                    hrs+=1;
                }
            }
            
            if(hrs>h){
                low=mid+1;
            }else{
                high=mid-1;
            }
            
        }
        
        return low;
        
        // for(int k=1;k<=maxi;k++){
        //     int x=sum/k;
        //     cout<<x<<" "<<sum<<" "<<k<<endl;
        //     if(x<h){
        //         return k;
        //     }
        // }
        
        // return -1;
    }
};