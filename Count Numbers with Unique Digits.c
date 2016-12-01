int permutation(int a, int b){
    if (a <= 0 || b <= 0) return 0;
    int res = a;
    for (int i = 1; i < b; i++){
        res *= --a;
    }
    return res;
}

int countNumbersWithUniqueDigits(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += permutation(10, i) - permutation(9, i-1);
    }
    return res == 0 ? 1 : res;
}