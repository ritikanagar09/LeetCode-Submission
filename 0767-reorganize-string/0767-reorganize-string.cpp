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
            // cout<<it.first<<" "<<it.second<<endl;
        }
        
        int k=n/2;
        k+=n%2;
        
        if(maxlen > k){
            return "";
        }
        
        
        
        int indx=0;
        
        // string str=s;
        vector<char>str(n);
        while(!pq.empty()){
            
            auto it=pq.top();
            int num=it.first;
            char k=it.second;
            pq.pop();
            // cout<<num<<endl;
            cout<<indx<<endl;
            while(num>0){
                str[indx]=k;
                indx+=2;
                num--;
                cout<<k<<" "<<num<<endl;
                cout<<indx<<endl;
                if(indx>=n){
                    indx=1;
                }
            }
            
            
        }
        
        string ans="";
        
        for(auto i:str){
            ans+=i;
        }
        
        return ans;
    }
};