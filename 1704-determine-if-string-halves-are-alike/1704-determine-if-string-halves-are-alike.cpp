class Solution {
public:
    int counter(string s){
        
        
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=tolower(s[i]);
            if(ch=='a' || ch=='i' || ch=='e' || ch=='o' || ch=='u'){
                cnt++;
            }
        }
        
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int mid=n/2;
        
        string left=s.substr(0,n/2);
        string right=s.substr(n/2,n/2);
        
        // cout<<left<<" "<<right<<endl;
        int cnt1=counter(left);
        int cnt2=counter(right);
        
        if(cnt1==cnt2){
            return true;
        }
        
        return false;
    }
};