class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        int totgas=0;
        int totcost=0;
        for(int i=0;i<n;i++){
            totgas+=gas[i];
            totcost+=cost[i];
        }
        
        if(totcost>totgas){
            return -1;
        }
        
        int start=0;
        int currfuel=0;
        for(int i=0;i<n;i++){
            
            
            if(currfuel<0){
                start=i;
                currfuel=0;
            }
            
            currfuel+=gas[i]-cost[i];
            
            
        }
        
        
        return start; 
    }
};