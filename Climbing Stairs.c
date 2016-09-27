int curse(int h, int* pres){
    if (h <= 1) return 1;
    if (!pres[h])
        for (int i = 1; i <= 2 && h - i >= 0; i++)
            pres[h] += curse(h-i, pres);
    return pres[h];
}

int climbStairs(int n) {
    int pres[n+1];
    memset(pres, 0, sizeof(pres));
    return curse(n, pres);
}