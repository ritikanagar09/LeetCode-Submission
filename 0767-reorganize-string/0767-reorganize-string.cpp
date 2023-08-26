class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        // cout<<n<<endl;
        map<char,int>mpp;
        
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        
        int maxlen=0;//max frequency
        priority_queue<pair<int,char>>pq;
        for(auto &it:mpp){
            maxlen=max(maxlen,it.second);
            pq.push({it.second,it.first});
        }
        
        int k=n/2;
        k+=n%2;
        
        if(maxlen > k){
            return "";
        }
        
        
        
        int indx=0;
        
        string str=s;
        while(!pq.empty()){
            
            auto it=pq.top();
            int num=it.first;
            char k=it.second;
            pq.pop();
            while(num--){
                str[indx]=k;
                indx+=2;
                // num--;
                if(indx>=n){
                    indx=1;
                }
            }
            
            
        }
        
        return str;
    }
};