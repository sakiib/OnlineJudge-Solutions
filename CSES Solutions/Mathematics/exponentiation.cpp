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
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << bigmod(a, b, mod) << endl;
    }
    return 0;
}
