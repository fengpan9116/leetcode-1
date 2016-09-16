bool isPowerOfFour(int num) {
    int zero = 0;
    int one = 0;
    while (num > 0){
        if (num&1) one++;
        else zero++;
        num >>= 1;
    }
    return (one == 1) && (zero%2 == 0);
}