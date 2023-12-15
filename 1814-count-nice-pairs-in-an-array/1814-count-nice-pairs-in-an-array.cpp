class Solution {
public:
    long long int mod=1e9+7;
    int reverseString(int x){
        string a=to_string(x);
        
        reverse(a.begin(),a.end());
        int y=stoi(a);
        return y;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>rev(n);
        
        for(int i=0 ;i < n;i++ ){
             int a=nums[i]; 
             rev[i]= reverseString(a);
        }
        
        map<long long int,long long int>mpp; 
        
        for(int i=0 ;i <n;i++){
            int a=nums[i];
            int b=rev[i] ;
            
            int diff= a-b;
            // cout<<a<<" "<<b<<" "<<diff<<endl;
            mpp[diff]++; 
        }
        
        long long int cnt=0;
        for(auto it: mpp ){
            if(it.second > 1){
                long long int x=it.second;
                cnt+= ((1LL * x*(x-1))/2LL);
            }
        }
        
        return cnt%mod;
    }
};