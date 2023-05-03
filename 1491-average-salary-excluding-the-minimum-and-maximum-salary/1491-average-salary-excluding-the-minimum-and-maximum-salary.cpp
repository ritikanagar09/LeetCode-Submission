class Solution {
public:
    double average(vector<int>& salary) {
        int maxi=*max_element(salary.begin(),salary.end());
        int mini=*min_element(salary.begin(),salary.end());
        
        double avg=0;
        for(int i=0;i<salary.size();i++){
            if(salary[i]!=maxi && salary[i]!=mini){
                avg+=salary[i];
            }
        }
        
        double ans=avg/(salary.size()-2);
        
        return ans;
    }
};