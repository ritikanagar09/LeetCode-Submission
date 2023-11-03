class Solution {
public:
    vector<string> buildArray(vector<int>& t, int n) {
        vector <string> ans;

        int i = 0;
        int j = 1;

        while ( i<t.size() && j<=n ) {

            ans.push_back("Push");

            if ( t[i] == j ) {
                i ++;
            }

            else {
                ans.push_back("Pop");
            }

            j++;
        }

        return ans;
    }
};