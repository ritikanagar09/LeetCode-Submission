class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // vector<datatype> vect -> here datatype is pair 
        vector<pair<int,int>> arr(n+1, {0,0});// N+1 ,we declare the size of vector 
        
        for(int i=0 ;i<trust.size();++i){
            
            arr[trust[i][0]].first +=1;// first postion sbki 
            arr[trust[i][1]].second +=1;
            
        }
        
        for(int j=1;j <=n;++j){
            if (arr[j].first==0 && arr[j].second==n-1){
                return j;
            }
        }
        
        return -1;
    }
};