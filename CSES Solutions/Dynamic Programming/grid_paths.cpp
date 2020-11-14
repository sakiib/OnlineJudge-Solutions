#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int x, int y, int mod) {
    return (x + y >= mod) ? x + y - mod: x + y;
}
int main() {
    int n;
    cin >> n;
    vector <string> s (n + 1);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector <vector <int> > dp (n + 1, vector <int> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        if (s[i][0] == '*') break;
        else dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (s[0][j] == '*') break;
        else dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (s[i][j] == '.') {
                dp[i][j] = add(dp[i - 1][j], dp[i][j - 1], mod);
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}
