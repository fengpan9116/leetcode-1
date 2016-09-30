void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (k == 0) return;
    int res[numsSize];
    memcpy(res+k, nums, (numsSize-k)*sizeof(int));
    memcpy(res, nums+numsSize-k, k*sizeof(int));
    memcpy(nums, res, sizeof res);
}