class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;
        queue<int>q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            if(top >=low && top <=high){
                ans.push_back(top);
            }
            
            if(top > high)break;
            int rem=top%10;
            if(rem < 9){
                rem++;
                int num=top*10+rem;

                q.push(num);
            }
            
            
            
        }
        
        return ans;
    }
};