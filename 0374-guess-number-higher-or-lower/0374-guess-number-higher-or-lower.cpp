/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i =1;
        int j = n;
        while(i<=j){
            int k = i-(i-j)/2;
            int f = guess(k);
            if(f ==0){
                return k;
            }
            else if( f== -1){
                j= k-1;
            }
            else{
                i=k+1;
            }
        }

        return -1;

    }
};