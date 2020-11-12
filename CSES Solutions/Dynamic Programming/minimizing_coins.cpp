#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int inf = 2e9;

int main() {
    int n, tot;
    cin >> n >> tot;
    vector <int> coin (n + 1);
    for (int i = 1; i <= n; i++) cin >> coin[i];
    vector <int> dp (1e6 + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= tot; j++) {
            dp[j] = min(dp[j], 1 + dp[j - coin[i]]);
        }
    }
    if (dp[tot] >= inf) cout << -1 << endl;
    else cout << dp[tot] << endl;
    return 0;
}
