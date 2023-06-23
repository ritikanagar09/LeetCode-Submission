//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    {   
        
        string temp="";
        int n=s.size();
        vector<string>v;
        for(int i=0;i<n;i++){
            
            string temp="";
            while(s[i]!='.'&&i<n){
                temp+=s[i];
                i++;
            }
            
            if(temp.size() > 0){
                v.push_back(temp);
            }
        }
        
        string ans="";
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            if(i>0){
                ans+=".";
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends