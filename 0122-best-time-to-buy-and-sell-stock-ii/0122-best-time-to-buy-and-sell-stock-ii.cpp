class Solution {
public:
    
int solve(int indx, int prev, vector<int>&arr){
    
        if(indx >=arr.size()){
            return 0;
        }

        int ans=0;
        if(prev!=-1 && arr[indx]>arr[prev]){
            ans=abs(arr[indx]-arr[prev]);
        }

        ans+=solve(indx+1,indx,arr);
        return ans;
}
    int maxProfit(vector<int>& prices) {
        return solve(0, -1,prices );
    }
};