int countPrimes(int n) {
    if (n <= 2) return 0;
    bool isPrime[n];
    memset(isPrime, 1, sizeof isPrime);
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            for (int j = i+i; j < n; j += i)
                isPrime[j] = false;
    int cnt = 0;
    for (int i = 2; i < n; i++)
        if (isPrime[i]) cnt++;
    return cnt;
}