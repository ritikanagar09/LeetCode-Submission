class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 1) return true;
        if(s[0] == '0') return false; // leading zeros not allowed
        if(n == 3 && s > "255") return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=3;j++) {
                for(int k=1;k<=3;k++){
                    if(i+j+k >= n || i+j+k+3 < n) continue;
                    string a = s.substr(0, i);
                    string b = s.substr(i, j);
                    string c = s.substr(i+j, k);
                    string d = s.substr(i+j+k);
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)){
                        res.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        }
        return res;
    }
};