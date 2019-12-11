//prime selection

class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof(isPrime));
        int primes[n];
        int cnt = 0, res = 0;
        for (int i = 2; i < n; i ++) {
            if (isPrime[i]) primes[cnt++] = i;
            for (int j = 0; j < cnt && i * primes[j] < n; j++) {
                isPrime[primes[j] * i] = false;
                if (i % primes[j] == 0) break;
            }
        }
        for (int i = 2; i < n; i ++) if (isPrime[i]) res ++;
        return res;
    }
};
