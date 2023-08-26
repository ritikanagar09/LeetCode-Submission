class Solution {
    unordered_map<string , bool> m;
    bool check(string s1, string s2, string s3,int l1, int l2, int l3, int p1, int p2, int p3){
        // base case
        if(p3==l3)
            if(p1==l1 && p2==l2)
                return true;
            else
                return false;
        
        
        string key =to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        // checking whther the key is already present or not 
        if(m.find(key)!=m.end())// matab key mil gyi h
            return m[key];
        
        
        //NOW THERE WILL BE THREE CONDITION
        
        // COND 1:
        // kya s1 puri complete ho gyi hai 
        if(p1==l1)
            if(s2[p2]==s3[p3])
                return m[key]=check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
            else
                return m[key]=false;
        
        // COND 2:
        
        if(p2==l2)
            if(s1[p1]==s3[p3])
                return m[key]=check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
            else
                return m[key]=false;
        
        //  COND 3:
        // AGAR DONO STRING PURI NHI HUI H ABHI TAKK
        
        // there might be possiblity ki humne 1st string se shuru kiya ho and may be second string se kiya ho 
        bool one=false; 
        bool two=false;
        
        if(s1[p1]==s3[p3])
            one=check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        
        if(s2[p2]==s3[p3])
            two=check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        
        return m[key]=one|| two;
    
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if((l1+l2)!=l3){
            return false;
        }else{
            return check(s1,s2,s3,l1,l2,l3,0,0,0);
        }
    }
};