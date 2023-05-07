class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        // min stores kar ke chlo 
        // buying will done onky on the day jab sabse kam price h
        int mini=1e8;
        int prof=0;
        for(int i=0;i<prices.size();i++){
            mini=min(prices[i],mini);
            prof=max(prof,prices[i]-mini);
        }
        
        return prof;
    }
};