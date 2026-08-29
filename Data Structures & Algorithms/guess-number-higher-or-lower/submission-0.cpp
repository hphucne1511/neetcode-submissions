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
        int next = n / 2;
        while(guess(next) != 0){
            if(guess(next) == -1) next /= 2;
            else if(guess(next) == 1) next += next / 2;
        }
        return next;
    }
};