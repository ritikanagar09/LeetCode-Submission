class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = growTime.size();
        vector<pair<int, int>> data;
        for(int i = 0 ; i < n ; i++){
            data.push_back({growTime[i], plantTime[i]});
        }
        sort(data.begin(), data.end(), greater<pair<int, int>>());
        int ans = 0;
        int growDays = 0;
        int plantDays = 0;
        for(auto el: data){
            plantDays += el.second;
            growDays = max(plantDays + el.first, growDays);
        }
        return growDays;
    }
};