#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <long long> a (n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] >= a[i - 1]) continue;
        ans += abs(a[i] - a[i - 1]);
        a[i] = a[i - 1];
    }
    cout << ans << "\n";
    return 0;
}
