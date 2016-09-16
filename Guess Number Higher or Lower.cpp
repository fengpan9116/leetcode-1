// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int max = n;
        int min = 1;
        int mid, res;
        while(1){
            mid = min + (max-min)/2;
            res = guess(mid);
            switch(res){
                case -1:
                    max = mid-1;
                    break;
                case 1:
                    min = mid+1;
                    break;
                default:
                    return mid;
            }
        }
    }
};