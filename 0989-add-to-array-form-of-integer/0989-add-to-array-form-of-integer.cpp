class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int>kk;
        string sk = to_string(k);
        for(int i =0 ; i<sk.size(); i++){
            kk.push_back(sk[i]-'0');
        }
        if(num.size()<kk.size()){
        while(num.size()<kk.size()){
            num.insert(num.begin(), 0);
        }
        }
        else if(num.size()>kk.size()){
        while(num.size()>kk.size()){
            kk.insert(kk.begin(),0);
        }
        }
        int n = kk.size();
        int ca =0;
        vector<int>ans;
        for(int i =n-1 ; i>=0; i--){
            int f = kk[i]+num[i] +ca;
            int nu = f%10;
            ca = f/10;
            ans.push_back(nu);
        }
        if(ca>0){
            ans.push_back(ca);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};