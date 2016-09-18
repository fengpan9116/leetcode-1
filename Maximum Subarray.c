#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int maxSubArray(int* nums, int numsSize) {
    // Kadane's algorithm
    int localmax = nums[0], gmax = nums[0];
    for (int i = 1; i < numsSize; i++){
        localmax = max(localmax+nums[i], nums[i]);
        gmax = max(localmax, gmax);
    }
    return gmax;
}