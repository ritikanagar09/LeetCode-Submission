class Solution {
public:
   // 12 3456 
    bool f(string kk,int a,int ans){
        //cout<<kk<<" "<<a<<" "<<ans<<endl;
        if(kk.size()==0  && ans == a){
            //cout<<a<<" "<<" true "<<endl;
            return true;
        }
        else if( kk.size()==0){
            return false;
        }
        
        for(int i =0; i<kk.size() ; i++){
             string x = kk.substr(0,i+1);
             if(x.size()>0){
                 ans += stoi(x);
                 string ss = kk.substr(i+1);
                  bool t = f(ss,a,ans);
                  ans -= stoi(x);
                  if(t==true){
                   return true;
                }
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
            int ans =0;
            y =i;
            // if(kk=="100" || kk=="10000" || kk== "10000"){
            //     y=1;
            // }
         bool t = f(kk,y,0);
            //cout<<t<<"//"<<kk << i <<endl;
            if(t){
                ans1+=k;
            }
        }
        return ans1;
    }
};