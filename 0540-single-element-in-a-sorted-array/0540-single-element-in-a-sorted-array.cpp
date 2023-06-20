class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // XOR 
        // 1^1=0    0^0=0  1^0=1   0^1=1
        // Basically if dfirrent to mai bachunga 
        // agar mera hum shakal aa jayega 
        // tho mai ushe maar dunga 
        
        int xor1=0;
        for(int i=0;i<nums.size();i++){
            xor1=xor1 ^ nums[i];
        }
        
        return xor1;
    }
};