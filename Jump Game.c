bool canJump(int* nums, int numsSize) {
    if (numsSize <= 1) return true;
    int maxSteps = nums[0];
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 0 && maxSteps <= i) return false;
        if (i+nums[i] > maxSteps) maxSteps = i+nums[i];
        if (maxSteps >= numsSize-1) return true;
    }
    return false;
}