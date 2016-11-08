/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int size = pow(2, n);
    *returnSize = size;
    int* res = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++){
        res[i] = i ^ (i >> 1);
    }
    return res;
}