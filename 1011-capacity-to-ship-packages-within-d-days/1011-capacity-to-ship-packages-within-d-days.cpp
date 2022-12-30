class Solution {
public:
    int numDays(vector<int>& weights, int mid, int maxi ){
        int parts=1;
        int sum=0;
        int i=0;
        
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
           
            if(sum>mid){
                sum=weights[i];
                parts++;
            }
        }
        
        
//         while(i<weights.size() and sum<=mid){
//                 sum+=weights[i++];
//                 if(sum>mid){
//                     i--;
//                     parts++;
//                     sum=0;
//                 }
//             }
        
        return parts;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int mini= *max_element(weights.begin(), weights.end());
        int maxi= accumulate(weights.begin(), weights.end(),0);
        if(days==1){
            return maxi;
        }
         int ans=INT_MAX;   
        int low=mini;
        int high=maxi;
        
        while(low<=high){
            
            int mid=(high-low)/2 + low;//10

            
            if(numDays(weights, mid, maxi) > days){
                low=mid+1;
            }else if(numDays(weights, mid, maxi) <= days){
                
                high=mid-1;
            }
            
        }
        
        
        return low;
            
    }
};