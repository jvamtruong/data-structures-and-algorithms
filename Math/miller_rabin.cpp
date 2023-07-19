#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
// the code below can check if a number is a prime up to 10 ^ 18
// time complexity : O(k*logN*logN) where k is the number of base values for the test

// if n is even then n is not prime (obviously)
otherwise we factor n - 1 into the form d * 2^s (where d is odd)

// do the test k times
if base^d = 1 (mod n) or if base^s = -1(mod n) with either one of s values from 0 to s - 1 every test 
then n is prime
// we can choose the number of base values based on how big n can get up to.
// with n <= 10^18 we can use the first 9 prime numbers to test
// with n <= 10^9 we can use {2, 7, 61} time complexity reduces to O(k*logN) 
because we no longer need the function mul_mod()

*/


long long base[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23}; 

long long mul_mod(long long a, long long b, long long MOD) {
    long long res = 0;
    while (b) {
        if (b & 1) res = (res + a) % MOD;
        a = (a << 1) % MOD;
        b >>= 1;
    }
    return res;
}

long long fpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n) {
        if (n & 1) res = mul_mod(res, a, MOD);
        a = mul_mod(a, a, MOD);
        n >>= 1;
    }
    return res;
}

bool test(long long n, long long d, long long s, long long a) {
    if (n == a) return true;
    long long p = fpow(a, d, n);
    if (p == 1) return true;
    for (int i = 0 ; i < s; i++) {
        if (p == n - 1) return true;
        p = mul_mod(p, p, n);
    }
    return false;
}

bool miller(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    long long d = n - 1;
    int s = 0;
    while (!(d & 1)) {
        s++;
        d >>= 1;
    }
    bool res = true;
    for (int i = 0 ; i < 9; i++) res &= test(n, d, s, base[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << (miller(n) ? "YES" : "NO");
}
