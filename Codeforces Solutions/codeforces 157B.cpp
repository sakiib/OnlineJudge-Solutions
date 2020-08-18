#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

string x;
int sum[7], res;

void solve(int i, int ch) {
    if (i == 6) {
        sum[0] = x[0] - '0';
        for (int j = 1; j < 6; j++) {
            sum[j] = sum[j - 1] + x[j] - '0';
        }
        int ls = sum[2], rs = sum[5] - ls;
        if (ls == rs) umin(res, ch);
        return;
    }
    for (char c = '0'; c <= '9'; c++) {
        char prv = x[i];
        x[i] = c;
        int add = (c != prv);
        solve(i + 1, ch + add);
        x[i] = prv;
    }
}

int main() {
    res = INF;
    cin >> x;
    solve(0, 0);
    cout << res << endl;
    return 0;
}
