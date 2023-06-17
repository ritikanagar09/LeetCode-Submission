class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        
        //lets suppose i becmes pehle khtm ..that means second array dalwana h hume 
        // but if j become khaali pehle that means usne pehle last ki empty position le li h 
        // ab i jnha par bnhi par h ..we dont require to do anything 
        
        // TC: O(m+n)
        while(i >=0 && j>=0){// dono me se ek bhi kam hua toh loop se bahar chle jayenge 
            // jo bhi bda h vo piche aa jayega 
            
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }else{
                nums1[k--]=nums2[j--];
            }
        }
        
        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};