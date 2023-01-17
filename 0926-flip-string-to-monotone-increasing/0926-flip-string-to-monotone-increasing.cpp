class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //HAR ITERATION ME JO MINIMUM HO VO FLIP HO JAO
        //BCOZ HUM COUNT KAR RHE HAI 
        
//         int count,flip=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='1'){
//                 count++;
//             }else{
//                 flip++;
//             }
            
//             flip=min(flip,count);
//         }
        
//         return flip;
        
        int cnt=0;
        int flip=0;
        for(auto i:s)
        {
            if(i=='0')
                flip++;
            else
                cnt++;
            flip=min(flip,cnt);
        }
        return flip;
    }
};