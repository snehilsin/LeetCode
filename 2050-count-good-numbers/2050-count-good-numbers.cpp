class Solution {
public:
    
const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int countGoodNumbers(long long n) {
    long long numberOfOddPlaces = n / 2;
    long long numberOfEvenPlaces = n / 2 + n % 2;
    return (power(5, numberOfEvenPlaces, MOD) * power(4, numberOfOddPlaces, MOD)) % MOD;
}
};