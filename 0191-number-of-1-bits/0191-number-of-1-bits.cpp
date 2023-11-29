class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int setBitCount = 0;
        
        while (n) { // equivalent to n != 0
            n &= (n - 1); // to clear the right most set bit
            ++setBitCount;
        }
        
        return setBitCount;
    }
};