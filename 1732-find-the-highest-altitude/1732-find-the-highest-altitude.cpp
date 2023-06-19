class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        
        int maxi=gain[0];
        for(int i=0;i<gain.size();i++){
            maxi=max(sum,maxi);

            sum+=gain[i];
        }
        maxi=max(sum,maxi);

        return maxi;
    }
};