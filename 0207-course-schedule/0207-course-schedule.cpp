class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){// i ke saare padosio ko dekh rahe hai
                indeg[it]++;
            }
        }
        
        queue<int>q;
        // int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
                // cnt++;
            }
        }
        
        vector<int>top;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // cnt++;
            top.push_back(node);
            
            for(auto a:adj[node]){
                indeg[a]--;
                if(indeg[a]==0){
                    q.push(a);
                }
            }
        }
        
        if(top.size()==numCourses){
            return true;
        }
        
        return false;
        
    }
};