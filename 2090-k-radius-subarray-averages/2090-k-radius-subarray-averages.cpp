class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        
        int n=nums.size();
        
        int left=-1;
        vector<int>ans;
        int right=0;
        long long sum=0;
        while(right<n){
            
            if(right-left< 2*k+1){
                sum+=nums[right];
                
            }else if(right-left==2*k+1){
                
                int win=2*k+1;
                if(left!=-1){
                    int m=nums[left];
                    sum-=m; 
                }
               
                sum+=nums[right];
                int avg=sum/win;
                ans.push_back(avg);
                
                
                left++;
            }
            
            right++;
        }
        
        
        
        int indx=0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            
            if(i-k>=0 && i+k<n){
                res[i]=ans[indx];
                indx++;
            }else{
                res[i]=-1;
            }
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int left=0;
//         int right=0;
//         bool flag=false;
//         int sum=0;
//         vector<int>ans;
        
        
        
//         while(right<n){
            
            
//             if(right-k <0){
//                 sum+=nums[right];
//                 ans.push_back(-1);
//                 cout<<sum<<endl;
                
//             }else if(right-k >=0 && right+k<n){
//                 int win=2*k+1;
//                 if(flag){
//                     int m=nums[left];
//                     sum-=m/win;
//                     sum+=nums[right]/win;
//                 }
                
//                 cout<<flag<<" "<<sum<<endl;
//                 int avg=sum/win;
//                 flag=true;
//                 ans.push_back(avg);
//                 left++;
                
            
            
//             }
//             else if(right+k>=n){
//                 ans.push_back(-1);
                
//             }
            
//             right++;
//         }
    
        
        
        
        return res;
    }
};