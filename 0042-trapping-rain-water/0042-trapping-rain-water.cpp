class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        vector<int>prev(n,0);
        prev[0]=height[0];
        
        vector<int>next(n,0);
        
        next[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prev[i]= max(prev[i-1],height[i]);
        }
        
        for(int i=n-2;i>=0;i--){
            next[i]=max(next[i+1],height[i]);
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            int area=min(next[i],prev[i])-height[i];
            maxi+=area;
        }
        
        return maxi;
    }
};