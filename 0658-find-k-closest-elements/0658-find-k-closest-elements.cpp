class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>ans;
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            int dif=abs(x-arr[i]);
            if(i<k){
                pq.push({dif,i});
            }
            else{
                if(pq.top().first > dif){
                    pq.pop();
                    pq.push({dif,i});
                }
            }
            
        }
        
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        vector<int>res;
        
        for(int i=0;i<ans.size();i++){
            res.push_back(arr[ans[i]]);
        }
        
        
        
        return res;
        
        
    }
};