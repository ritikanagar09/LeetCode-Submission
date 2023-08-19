class Solution {
public:
    bool solveMem(string &s1, string &s2, int i, int j, int cnt) {
        if(i == s1.size() && j == s2.size() && cnt == 0) return true;
        if(j == s2.size() && cnt > 0) return false;
        if(i == s1.size() && cnt > 0) return false;
        if(cnt == 0) return true;
        
        int op1 = 0, op2 = 0;
        
        if(s1[i] == s2[j] || (int)s1[i] + 1 == (int)s2[j] || (s1[i] == 'z' && s2[j] == 'a')) {
            return solveMem(s1, s2, i + 1, j + 1, cnt - 1);
        }
        return solveMem(s1, s2, i + 1, j, cnt);
    }
    bool canMakeSubsequence(string str1, string str2) {
        return solveMem(str1, str2, 0, 0, str2.size());
    }
};