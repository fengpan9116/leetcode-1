class NumArray {
public:
    NumArray(vector<int> &nums) {
        m_nums.assign(nums.begin(), nums.end());
    }

    int sumRange(int begin, int end) {
        int res = 0;
        for (int i = begin; i <= end; i++)
            res += m_nums[i];
        return res;
    }
private:
    vector<int> m_nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);