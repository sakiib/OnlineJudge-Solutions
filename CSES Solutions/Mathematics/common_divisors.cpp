#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int cnt[N];

vector <int> divisors(int n) {
    int x = sqrt(n);
    vector <int> ret;
    for (int i = 1; i <= x; i++) {
        if (n%i == 0) {
            ret.push_back(i);
            if (n/i != i) ret.push_back(n/i);
        }
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vector <int> d = divisors(x);
        for (auto val: d) cnt[val]++;
    }

    int ans = 0;
    for (int i = 1; i <= 1e6; i++) {
        if (cnt[i] >= 2) ans = i;
    }
    assert(ans != 0);
    cout << ans << "\n";
    return 0;
}
