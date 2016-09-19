class Solution {
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        original = nums;
        v = original;
        size = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        v = original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(v.begin(), v.end());
        return v;
    }
private:
    vector<int> original;
    vector<int> v;
    size_t size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */