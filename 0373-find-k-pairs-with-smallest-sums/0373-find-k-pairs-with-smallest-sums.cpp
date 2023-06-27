class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        map<pair<int,int>,int>m;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({a[0]+b[0],0,0});
        vector<vector<int>>ans;
        while(k-- and pq.size()){
            auto v = pq.top();
            pq.pop();
            int i = v[1],j=v[2];
            if(j+1<b.size() and m.find({i,j+1})==m.end()){
                 pq.push({a[i]+b[j+1],i,j+1});
                  m[{i,j+1}]++;
            } 
            if(i+1<a.size() and m.find({i+1,j})==m.end()){
                pq.push({a[i+1]+b[j],i+1,j});
                m[{i+1,j}]++;
            }
            cout<<endl;
            ans.push_back({a[i],b[j]});
        }
        return ans;
    }
};