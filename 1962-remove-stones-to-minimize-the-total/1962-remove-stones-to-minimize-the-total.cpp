class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n=piles.size();
        for(auto i:piles){
            pq.push(i);
        }
        
        while(!pq.empty() && k>0){
            int top=pq.top();
            pq.pop();
            int r=top/2;
            int res=top-r;
            pq.push(res);
            k--;
        }
        
        int sum=0;
        
        while(!pq.empty()){
            int top=pq.top();
            sum+=top;
            pq.pop();
        }
        
        return sum;
        
        
    }
};