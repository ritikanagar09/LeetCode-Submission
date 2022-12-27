class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int>req(n);
        for(int i=0;i<rocks.size();i++){
            int r=capacity[i]-rocks[i];
            req[i]=r;
        }
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto i:req){
            pq.push(i);
        }
        
        int ans=0;
        while(!pq.empty() && additionalRocks>0 ){
            int top=pq.top();
            pq.pop();
            additionalRocks-=top;
            if(additionalRocks>=0){
                ans++;
            }
            
        }
        
        return ans;
    }
};