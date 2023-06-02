class Solution {
    
private:
    bool checkBi(int node, vector<vector<int>>& graph, vector<int>&colr){


	    

	
		for(auto adjnode:graph[node]){
			if(colr[adjnode]==-1){
				colr[adjnode]=!colr[node];
                if(!checkBi(adjnode,graph,colr)){
                    return false;
                }
				
			}else if(colr[adjnode]==colr[node]){
				return false;
			}
		}
	

	return true;
}
    
    

public:
    bool isBipartite(vector<vector<int>>& graph) {
        
    int n=graph.size();
    int m=graph[0].size();
    vector<int>colr(n,-1);


	for(int i=0;i<n;i++){
		if(colr[i]==-1){
			if(!checkBi(i,graph,colr)){
                colr[i]=0;
				return false;
			}
		}
	}


	    return true;
    }
};