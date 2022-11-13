class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        cout<<n<<endl;
        int i=n-1;
        int j=i;
        string str="";
        
       //hello world
        
        while(j>=0)
            
        { 
            cout<<"///"<<endl;
            cout<<i<<" "<<j<<endl;
           
            if(s[j]==' '){
                while(j!=-1 && s[j]==' ' ){
                    j--;
                }
                i=j;
            }else{
                
                while(j!=-1 && s[j]!=' ' ){     
                    cout<<"-----"<<endl;
                    j--;
                }   


                 str.append(s,j+1,i-j);
                 str+=" ";
                 cout<<str<<endl;
                 //i=j-1;

                 i=j;
            }
           
         cout<<"^^ "<<i<<" "<<j<<endl;
            
        }
        
        if(str[str.length()-1]==' '){
            str.erase(str.begin() + str.length()-1);
        }
      
       return str;
        
    }
};