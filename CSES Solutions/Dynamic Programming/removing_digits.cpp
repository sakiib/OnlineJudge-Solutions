#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9;

vector <int> v[N];
int dp[N];

int solve(int cur) {
    if (cur == 0) return 0;
    if (dp[cur] != -1) return dp[cur];
    int ret = inf;
    for (auto x: v[cur]) {
        ret = min(ret, solve(cur - x) + 1);
    }
    return dp[cur] = ret;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur) {
            int x = cur%10;
            if (x != 0) v[i].push_back(x);
            cur /= 10;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(n) << "\n";
    return 0;
}
