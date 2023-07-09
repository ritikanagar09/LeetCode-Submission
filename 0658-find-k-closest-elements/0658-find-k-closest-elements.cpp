class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>ans;
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<n;i++){
            int dif=abs(arr[i]-x);
                pq.push({dif,i});
            
        }
        
        while(!pq.empty() && k--){
            int indx=pq.top().second;
            ans.push_back(indx);
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