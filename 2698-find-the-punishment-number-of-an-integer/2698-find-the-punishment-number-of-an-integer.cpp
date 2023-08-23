class Solution {
public:
   // 12 3456 
    bool f(string kk,int a,int ans){
        if(kk.size()==0){
            return ans==a;
        }
        
        if(ans > a){
            return false;
        }
        for(int i =0; i<kk.size() ; i++){
                string x = kk.substr(0,i+1);
                string ss = kk.substr(i+1);
                int k=stoi(x);
                 
                  bool t = f(ss,a,ans+k);
                  // ans -= stoi(x);
                  if(t){
                        return true;
                    }    
        }
        return false;
    }
    int punishmentNumber(int n) {
        
        int ans1 =0;
        int y = 0;
        for(int i =1; i<=n ; i++){
            int k = pow(i,2);
            string kk = to_string(k);
            bool t = f(kk,i,0);
            if(t){
                ans1+=k;
            }
        }
        return ans1;
    }
};