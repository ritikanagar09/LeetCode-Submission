class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // THIS PROBELM CAN SOLVED USING EARLIEST DEADLINE FIRST ALGORITHM 
        // IN WHICH THE WORK WHICH WOULD BE FINSHED FIRST SHOULD BE DONE FIRST ALSO
        int n = pairs.size(), ctr = 1;
	sort(pairs.begin(), pairs.end(), [&] (auto a, auto b) {return a[1] < b[1];});       // Sort the input matrix with respect to second element
	int prev = pairs[0][1];
	for(int i = 1; i < n; ++i){
		if(pairs[i][0] > prev){
			ctr++;
			prev = pairs[i][1];
		}
	}
	return ctr;
    }
};