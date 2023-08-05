class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n=nums.size();
        
        map<int,vector<int>>mpp; //  for storing elemnet and its indexes
        
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        
        
        int mindist=INT_MAX;
        for(auto &[ele,posVec]:mpp){ // posVec->position vector
            int x=posVec[0]+n;
            posVec.push_back(x);
            
            
            int gap=0;
            for(int j=1;j<posVec.size();j++){
                gap=max(gap, (posVec[j]-posVec[j-1])/2);
            }
            
           
            mindist=min(mindist,gap);
        }
        
        
        return mindist;
    }
};