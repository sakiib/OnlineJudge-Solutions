#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
#define MODL 1000000007

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll modularExpo(ll x, ll y, ll mod) {
    ll res = 1;
    x = x % mod;

    while(y > 0) {
        // if y is odd
        if(y & 1)
            res = ((__int128)res * x) % mod;

        x = ((__int128)x * x) % mod;
        y >>= 1;
    }

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    ll a, b, n;
    while(t--) {
        cin >> a >> b >> n;

        ll an = modularExpo(a, n, MODL);
        ll bn = modularExpo(b, n, MODL);

        if(a==b) {
            cout << (an+bn) % MODL << endl;
            continue;
        }
        ll ans = gcd(an+bn, a-b);
        cout << ans%MODL << endl;
    }

    return 0;
}
