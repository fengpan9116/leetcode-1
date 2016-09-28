#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
     
int integerBreak(int n) {
    int dyna[n+1];
    memset(dyna, 0, sizeof dyna);
    for (int i = 1; i < n; i++){
        for (int j = 1; j < i+1; j++){
            if (i + j > n) break;
            dyna[i+j] = max(max(dyna[i], i) * max(dyna[j], j), dyna[i+j]);
        }
    }
    return dyna[n];
}