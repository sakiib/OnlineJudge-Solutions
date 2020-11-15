#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector < int > p(n), a(m);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> a[i];

    sort(p.begin(), p.end());
    sort(a.begin(), a.end());

    int ans = 0, l = 0, r = 0;
    while (l < n && r < m) {
        if (abs(p[l] - a[r]) <= k) ans++, l++, r++;
        else if (p[l] < a[r]) l++;
        else r++;
    }
    cout << ans << "\n";
    return 0;
}
