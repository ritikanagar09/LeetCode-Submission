class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        set<pair<int,int>>s;
        
        
        int isum=nums1[0]+nums2[0];
        pq.push({isum,{0,0}});
        s.insert({0,0});
        
        vector<vector<int>>res;
        for(int cnt=0;(cnt<k && !pq.empty()) ;cnt++){
            auto temp=pq.top();
            
            pq.pop();
            pair<int,int>p=temp.second;
            
            vector<int>ans;
            int i=p.first;
            int j=p.second;
            
            ans.push_back(nums1[i]);
            ans.push_back(nums2[j]);
            
            res.push_back(ans);
            
            // cout<<i<<" "<<j<<endl;
            
            if(i+1<n  && (s.find({i+1,j})==s.end())){
                int sum1=nums1[i+1]+nums2[j];
                pq.push({sum1,{i+1,j}});
                s.insert({i+1,j});
            }
            
            
            
            if(j+1<m &&  (s.find({i,j+1})==s.end())){
                int sum2=nums1[i]+nums2[j+1];
                pq.push({sum2,{i,j+1}});
                s.insert({i,j+1});
            }
            
            
        }
        
        
        return res;
    }
};