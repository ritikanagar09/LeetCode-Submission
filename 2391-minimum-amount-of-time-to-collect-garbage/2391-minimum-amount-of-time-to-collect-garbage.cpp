class Solution {
public:
    
    int count(string g, char ch){
        int cnt=0;
        for(auto i:g){
            if(i==ch)cnt++;
        }
        return cnt;
        
    }
    
    int check(vector<string>& garbage, int j, char ch){
       
        for(int i=j ;i<garbage.size();i++){
            string s=garbage[i];
            
            if(count(s, ch)!=0){
                return true;
                
            }
        }
        
        return false;
    }
    
    int solve(vector<string>& garbage, char ch, vector<int>& travel){
        int time1=0;
        for(int i=0 ;i<garbage.size();i++){
            string g= garbage[i];
            int t=count(g,ch);
            if(t!=0){
                time1+=t;
                
            }
            cout<<time1<<endl;
            
            if(check(garbage, i+1 ,ch)){
                    
                  if(i!=0){
                    time1+=travel[i-1];
                  }  
            }else{
                if(i!=0){
                     time1+=travel[i-1];
                  }
                break;
            }

        }
        
        return time1;
    }
    
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        return solve(garbage, 'G',travel)+solve(garbage, 'P',travel)+solve(garbage, 'M',travel);
    }
};