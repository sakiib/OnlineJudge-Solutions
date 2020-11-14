#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tot;
    cin >> n >> tot;

    vector <int> cost (n + 1);
    vector <int> val (n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i <= n; i++) cin >> val[i];

    vector <vector <int> > dp(n + 1, vector <int> (tot + 1, 0));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= tot; c++) {
            if (cost[i] <= c) {
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-cost[i]] + val[i]);
            }
            else {
                dp[i][c] = dp[i-1][c];
            }
        }
    }
    cout << dp[n][tot] << "\n";
    return 0;
}
