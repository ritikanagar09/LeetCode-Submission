class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        
        int n=tasks.size();
       
       for(int i=0;i<n;i++){
           tasks[i].push_back(i);
       }
        sort(tasks.begin(), tasks.end());
        
        priority_queue<pair<long long,int>, vector<pair<long long ,int>>, greater<pair<long long,int>> > pq;
        
        long long finishTime=tasks[0][0];
        vector<int> ans;
        int i=0;
        while(i<n || !pq.empty()){
            while(i<n && finishTime>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            
            
            int index=pq.top().second;
            long long procTime=pq.top().first;
            
            pq.pop();
            finishTime+=procTime;//5
            
           
            ans.push_back(index);//0,2
            if(i<n && finishTime <=tasks[i][0] && pq.empty()){ // CPU IDLE HAI 
                finishTime=tasks[i][0];
            }
            
        }
    
        return ans;
        
       
       
    }
};