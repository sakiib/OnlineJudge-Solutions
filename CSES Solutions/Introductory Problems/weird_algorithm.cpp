#include <bits/stdc++.h>
using namespace std;

vector <long long> ans;

void solve(long long n) {
    ans.push_back(n);
    if (n == 1) return;
    if (n&1) solve(3 * n + 1);
    else solve(n / 2);
}
int main() {
    int n;
    cin >> n;
    solve(n);
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    return 0;
}
