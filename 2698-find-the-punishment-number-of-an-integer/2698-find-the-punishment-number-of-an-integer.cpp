class Solution {
public:
    bool solve(int indx, string &s, int curr, int sum){
        
        if(indx>=s.size()){
            return curr==sum;
        }
        
        if(curr>  sum )return false;
        
        
        
        
        for(int i=indx;i<s.size();i++){
            string str=s.substr(indx,i-indx+1);
            int k=stoi(str);
            
            // cout<<k<<" "<<sum<<endl;
            if(solve(i+1,s,curr+k,sum)){
                return true;
            }
            
            // sum+=k;
             
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        
//         if(n <=8){
//             return 1;
//         }else if(n <=10){
//             return 182;
//         }else if(n<=40){
//             return 1478;
//         }
                 
//         int sum=1478;
        int sum=0;
        // string s="1296";
        // int ans=solve(0,s,0,36);
        // cout<<"//"<<ans<<endl;
        for(int i=1;i<=n;i++){
            
            string s=to_string(i*i);
            // cout<<"//"<<endl;
            if(solve(0,s,0,i)){
                sum+=i*i;
                // cout<<i<<endl;
            }
        }
                 
        return sum;
    }
};