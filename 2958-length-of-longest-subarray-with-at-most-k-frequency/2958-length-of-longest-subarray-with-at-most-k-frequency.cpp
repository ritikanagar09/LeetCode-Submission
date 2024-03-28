class Solution {
public:
    Solution(){ // constructor to be run before the solution --> lower time complexity
        // Fast input
        ios::sync_with_stdio(false); std::cin.tie(nullptr);
    }
    unordered_map<int , int> freq_mp; // prefered rather than ordered map as we do not need sorting
    
    int maxSubarrayLength(vector<int>& nums, int k) {
         
        int sz = nums.size(), // size            
        max_size = 0, // max size for window
        head = 0 , tail = 0; // pointers used in sliding window
        
        while( head < sz && tail <=head ){ // 
            freq_mp[nums[head]]++; // character apeared here
            
            if(freq_mp[nums[head]] <= k){ 
                max_size = max(max_size , (head - tail + 1)); // head - tail + 1 --> size of the window
                head++; // increasing window size from head [right]
            } else{ // decreaseing window size from tail [left]
                while(freq_mp[nums[head]] > k){ // keep decrease until a size with good repition
                    freq_mp[nums[tail]]--;
                    tail++; // moving left pointer to the right one step
                }
                max_size = max(max_size , (head - tail + 1)); // finding the new max if exist before moving head
                head++;
            }
        }
        return max_size;
    }
};