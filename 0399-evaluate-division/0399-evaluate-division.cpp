class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>adj;
    double qans;
    bool dfs(string src, string dest,unordered_map<string,bool>&vis, double prod){
        
        if(src==dest){
            qans=prod;
            return true;
        }
        cout<<src<<endl;
        vis[src]=true;
        
        bool temp=false;
        for(int i=0;i<adj[src].size();i++){
                string ndest=adj[src][i].first;
                double wt=adj[src][i].second;
                
                cout<<src<<" "<<ndest<<" "<<wt<<endl;
                
                if(vis[ndest]==false){
                    // prod=prod*wt;
                    temp=dfs(ndest,dest,vis,prod*wt);
                }
            
            if(temp){
                break;
            }
            
           
        }
        
        
        return temp;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        
        int n=equations.size();
        unordered_map<string,bool>vis;
        for(int i=0;i<n;i++){
            string x=equations[i][0];
            string y=equations[i][1];
            double wt=values[i];
            
            adj[x].push_back({y,wt});
            adj[y].push_back({x,1.0/wt});
            
            vis[x]=false;
            vis[y]=false;
            
            
        }
        
        unordered_map<string,bool>vis1=vis;
        vector<double>res;
        for(auto q:queries){
            string src=q[0];
            string dest=q[1];
            double ans=-1.0;
            double prod=1.0;
            
            bool flag=false;
            if(adj.find(src)!=adj.end() && adj.find(dest)!=adj.end()){
                flag=dfs(src,dest,vis1, prod);
                
            }
            
            // if(ans==0.0){
            //     res.push_back(-1.0);
            // }else{
            //     res.push_back(ans);
            // }
            
            if(flag){
                ans=qans;
            }
            
            res.push_back(ans);
            vis1=vis;
            
            
        }
        
        return res;
        
        
    }
};