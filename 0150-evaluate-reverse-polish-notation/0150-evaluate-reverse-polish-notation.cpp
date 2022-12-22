class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        
        for(int i=0;i<n;i++){
            string s= tokens[i];
            if(s=="*"||s=="+"||s=="-"||s=="/"){
                int A=st.top();
                st.pop();
                int B=st.top();
                st.pop();
                int res=0;
                if(s=="*"){
                    res=A*B;
                }else if(s=="+"){
                    res=A+B;
                }else if(s=="-"){
                    res=B-A;
                }else{
                    res=B/A;
                }
                st.push(res);
            }
            else{
                int k=stoi(s);
                st.push(k);     
            }
        }
        
            if(!st.empty()){
                return st.top();
            }
            

            return -1;
    }
};