class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long> sums;
        long prevsum = n;
        while(prevsum != 1){
            if (sums.count(prevsum)) return false;
            sums.insert(prevsum);
            long div = 10, cursum = pow(prevsum % 10, 2);
            while(prevsum/div){
                cursum += pow((prevsum/div) % 10, 2);
                div *= 10;
            }
            prevsum = cursum;
        }
        return true;
    }
};