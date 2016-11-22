int mySqrt(int x) {
    float res;
    float in = x;
    __asm__
        ("fld %1;"
         "fsqrt;"
         "fstp %0;"
         : "=m" (res)
         : "m"  (in)
         );
    return (int)res;
}