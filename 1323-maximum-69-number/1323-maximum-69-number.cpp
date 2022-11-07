class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int n=s.length();
        vector<int>v;
        for(int i=0;i<n;i++){
            string t=s;
            if(s[i]=='6'){
                t[i]='9';
                int k= stoi(t);
                v.push_back(k);
            }
        }
        
        if(v.size()==0){
            return num;
        }
        
        sort(v.rbegin(),v.rend());
        
        return v[0];
        
    }
};