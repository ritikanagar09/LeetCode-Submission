class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>f(26);
        for(int i=0;i<sentence.length();i++){
            int k=sentence[i]-'a';
            cout<<sentence[i]<<" "<<k<<endl;
            f[k]=1;
        }
        
        int sum=0;
        
        for(int i=0;i<f.size();i++){
            cout<<f[i]<<endl;
            sum+=f[i];
        }
        // cout<<sum<<endl;
        if(sum==26){
            return true;
        }else{
            return false;
        }
 
    }
};