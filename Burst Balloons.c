#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
     
int curse(int* nums, int size, int dyna[][size], int left, int right){
    if (left == right-1) return 0;
    if (!dyna[left][right]){
        for (int i = left+1; i < right; i++){
            dyna[left][right] = max(dyna[left][right], nums[left]*nums[i]*nums[right]
            + curse(nums, size, dyna, left, i) + curse(nums, size, dyna, i, right));
        }
    }
    return dyna[left][right];
}

int maxCoins(int* nums_, int numsSize) {
    int *nums;
    int size = numsSize + 2;
    nums = (int*)malloc(size*sizeof(int));
    memcpy(nums+1, nums_, numsSize*sizeof(int));
    nums[0] = 1;
    nums[size-1] = 1;
    int dyna[size][size]; // ok for c99
    memset(dyna, 0, sizeof dyna);
    int res = curse(nums, size, dyna, 0, size-1);
    free(nums);
    return res;
}