#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int val;
int dp[N];

int solve(int tot) {
    if (tot > val) return 0;
    if (tot == val) return 1;
    if (dp[tot] != -1) return dp[tot];
    int ret = 0;
    for (int i = 1; i <= 6; i++) {
        ret += solve(tot + i)%mod;
        ret %= mod;
    }
    return dp[tot] = ret;
}
int main() {
    cin >> val;
    memset(dp, -1, sizeof(dp));
    cout << solve(0) << endl;
    return 0;
}
