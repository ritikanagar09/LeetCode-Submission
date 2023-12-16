class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
         int a,b,c,m;
        long tmp, res;
        vector<int> ans;
        int i = 0;
        for (auto variable : variables) {
            a = variable[0];
            b = variable[1];
            c = variable[2];
            m = variable[3];
            a = a % 10;
            res = 1;
            for (int j = 0; j < b ; ++j) {
                res = (res * a) % 10;
             }
            tmp = res % m;
            res = 1;
            for (int j = 0; j < c ; ++j) {
                res = (res * tmp) % m;
             }
            if (res == target) {
                ans.push_back(i);
            }
            ++i;
        }
    return ans;
    }
};