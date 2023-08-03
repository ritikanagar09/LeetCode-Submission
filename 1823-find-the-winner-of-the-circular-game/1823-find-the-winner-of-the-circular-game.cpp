class Solution {
public:
    int findTheWinner(int n, int k) {
        
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        
        while(q.size()!=1){
            int x=k;
            while(x>1){
                int elem=q.front();// elemnts to skipped ..inko piche daaldo queue me 
                q.pop();
                q.push(elem);
                x--;
            }
            
            q.pop();
        }
        
        return q.front();
    }
};

