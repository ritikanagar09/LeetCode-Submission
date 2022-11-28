class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int m=matches.size();
        vector<vector<int>> res(2);
        // vector<int> v1;
        // vector<int> v2;
        set<int> winn;
        // vector<int> loses;
        // map<int, int> win;
        map<int, int> lose;
        
        // to calculate who have lost one match
        for(int i=0 ;i<m;i++){
            lose[matches[i][1]]++;
            // win[matches[i][0]]++;
            // if(find(winn.begin(), winn.end(), matches[i][0]) == winn.end())
            //     {winn.push_back(matches[i][0]);}
            
            winn.insert(matches[i][0]);
            
            
            // if(find(loses.begin(), loses.end(), matches[i][1]) == loses.end())
            //     {loses.push_back(matches[i][1]);}
        }
        
        for(auto i:lose){
            if(i.second==1){
                res[1].push_back(i.first);
                
            }
            
            
        }
        
        
        for(int i: winn){
            if(!lose.count(i)){
                res[0].push_back(i);
            }
        }
        
        
        
//         for(int i=0 ;i<winn.size();i++){
//             if(find(loses.begin(), loses.end(), winn[i]) == loses.end()){
//                 v1.push_back(winn[i]);
//             }
//         }
//         // sort(v1.begin(),v1.end());
//         vector<char> v1(winn.begin(), winn.end());
//         sort(v2.begin(),v2.end());
        
        // res.push_back(v1);
        // res.push_back(v2);
        return res;
        
        
    }
};