#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long bigmod(long long b, long long p, long long mod) {
    long long res = 1 % mod, x = b % mod;
    while (p) {
        if (p & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        p >>= 1;
    }
    return res % mod;
}
int main() {
    int n;
    cin >> n;
    cout << bigmod(2, n, mod) << "\n";
    return 0;
}
