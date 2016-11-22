int mySqrt(int x) {
    // SSE
    double res;
    double in = x;
    __asm__ (
            "movq %1, %%xmm0;"
            "sqrtsd %%xmm0, %%xmm1;"
            "movq %%xmm1, %0;"
            : "=r"(res)
            : "g"(in)
            : "xmm0", "xmm1", "memory"
            );
    return (int)res;
}