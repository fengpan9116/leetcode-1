#ifndef DBL_MAX
#define DBL_MAX 1.7976931348623157E+308
#endif

#ifndef DBL_MIN
#define DBL_MIN 2.2250738585072014e-308
#endif

double myPow(double xx, int n) {
    if (n == 0) return 1;
    double res = 1, pres = 1, x = xx;
    unsigned abspow = abs(n);
    while (abspow > 0){
        if (abspow & 1) res *= x;
        x *= x;
        abspow /= 2;
    }
    if (n < 0) res = 1/res;
    return res;
}