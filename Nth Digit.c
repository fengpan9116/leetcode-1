int findNthDigit(int n) {
    long cap = 9, nd = 1, cirno = 9, res = n;
    while (cap < n){
        nd++;
        cirno = 9 * pow(10,nd-1)*(nd);
        cap += cirno;
    }
    n -= cap - cirno;
    int sb = n % nd;
    if (sb != 0) sb = nd - sb;
    if (nd > 1){
        if (sb == nd-1){
            res = (ceil)((long double)n/(long double)nd/powl(10, sb));
            if (res < 1) res = 1;
        }
        else res = ((n/(nd-sb))-1) % 10;
    }
    return res;
}

