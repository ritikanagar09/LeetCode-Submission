class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int count = 1;
        for(int i=0; i<chars.size(); i++){
            ans.push_back(chars[i]);
            while(i<chars.size()-1 && chars[i]==chars[i+1]){
                count++;
                i++;
            }
            if(count>1 && count<10){
                ans.push_back(count+'0');
            }
            if(count>=10){
               int b = count;
               string temp = to_string(b); 
               for(int i=0; i<temp.length(); i++){
                   ans.push_back(temp[i]);
               }
            }
            count = 1;
        }
        chars = ans;
        return chars.size();
    }
};