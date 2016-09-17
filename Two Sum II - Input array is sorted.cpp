class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lptr = 0, rptr = numbers.size()-1, sum;
        while(lptr < rptr){
            sum = numbers[lptr] + numbers[rptr];
            if (sum < target) lptr++;
            else if (sum > target) rptr--;
            else return {lptr+1, rptr+1};
        }
        return {-1, -1};
    }
};