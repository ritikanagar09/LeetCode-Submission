class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        
        int longest = INT_MIN;
        
        // map will store the types of fruit in a window
       
        unordered_map<int, int> mp;
        
        int left = 0;
        
        for(int right = 0; right < n; right++)
        {
            // insert the curr fruit into map
            
            mp[fruits[right]]++;
            
            // remove the fruits from left, untill there is only two type of fruits in map
            
            while(left <= right && mp.size() > 2)
            {
                mp[fruits[left]]--;
                
                if(mp[fruits[left]] == 0)
                {
                    mp.erase(fruits[left]);
                }
                
                left++;
            }
            
            // update longest
            
            int curr_len = right - left + 1;
            
            longest = max(longest, curr_len);
        }
        
        return longest;
    }
};