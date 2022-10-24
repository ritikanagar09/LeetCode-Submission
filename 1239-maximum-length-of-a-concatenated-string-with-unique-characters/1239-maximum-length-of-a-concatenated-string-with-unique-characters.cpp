class Solution {
public:
    bool isValid(string &s1,string &s2){
        unordered_set<char> st;
        for(auto i : s2){
            if(st.find(i) != st.end()) return false;
            for(auto j : s1){
                if(i == j) return false;
            }
            st.insert(i);
        }
        return true;
    }
    int f(int i,string curr,vector<string> &arr,unordered_map<string,int> &map){
        if(i == arr.size()){
            return curr.size();
        }
        if(map.find(curr) != map.end()) return map[curr];
        int notTake = f(i+1,curr,arr,map);
        int take = 0;
        if(isValid(curr,arr[i])){
            take = f(i+1,curr+arr[i],arr,map);
        }
        return map[curr] = max(take,notTake);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<string,int> map;
        return f(0,"",arr,map);
    }
};