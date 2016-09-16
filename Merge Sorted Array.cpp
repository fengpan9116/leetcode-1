class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m, nums1.end());
        nums2.erase(nums2.begin()+n, nums2.end());
        for (auto it = nums1.begin(); it != nums1.end(); it++){
            if (nums2.empty()) break;
            if (nums2[0] < *it){
                nums1.insert(it, nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        if (!nums2.empty()) nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    }
};