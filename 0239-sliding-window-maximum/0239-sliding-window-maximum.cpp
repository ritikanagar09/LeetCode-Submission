class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
     priority_queue<pair<int,int>> pq; // element -> index
    // vec to store the results
    vector<int> res;
    // left and right bound of our window
    int right = 0, left = 0;

    // outer loop
    while(right < arr.size())
    {
        // add every element into the PQ
        pq.push({arr[right] , right});
        // window is not full... expand it
        if(right - left + 1 < k)
            right++;
        // window is full
        else if(right - left + 1 == k)
        {
            // remove the element not in the window from the PQ
            while(pq.top().second < left)
                pq.pop();
            // push the max elemnet from the window into the PQ
            res.push_back(pq.top().first);
            // slide the window
            left++; right++;
        }
    }
    return res;
    }
};