class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        map<string,int>m1,m2;
        int n = w.size();
        for(int i =0 ; i<n ; i++){
            if(w[i][0]==w[i][1]){
                m2[w[i]]++;
            }
            else{
                m1[w[i]]++;
            }
        }
        int count =0;
        for(auto i : m1){
            // cout<<i.first<<" //"<<i.second<<endl;
            string s = i.first;
            string k = s;
            reverse(k.begin(), k.end());
            int a = m1[s];
            int b =0;
            if( m1.find(k)!=m1.end()){
                b =m1[k];
            }
            count+= min(a,b)*4;
            m1[s] =0;
        }
         // cout<<count<<" "<<endl;
        int ev =0;
        int maxi = 0;
        for(auto i:m2){
             // cout<<i.first<<" //"<<i.second<<endl;
            if(i.second%2==0){
                ev++;
                count+=2*(i.second);
            } 
            else{
                count += 4*(i.second/2);
                maxi = max(maxi, i.second);
            }
            
      }
        if(maxi%2 !=0){
            count+=2;
        }
        return count;
    }
};