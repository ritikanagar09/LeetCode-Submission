class Solution {
public:
    
    bool canpart(string s, int target){
        if(s=="" && target==0){
            return true;
        }
        
        if(target<0){
            return false;
        }
        
        
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i+1);
            string right=s.substr(i+1);
            int leftnum=stoi(left);
            
            bool flag=canpart(right,target-leftnum);
            if(flag){
               return true;
            }
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        
        
        int sum=0;
        for(int i=1;i<=n;i++){
            if(canpart(to_string(i*i),i)){
                sum+=i*i;
            }
        }
        
        return sum;
        
    }
};