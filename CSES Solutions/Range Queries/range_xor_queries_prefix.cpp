#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int val[N], prefix[N];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) prefix[i] = (prefix[i - 1] ^ val[i]);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (prefix[r] ^ prefix[l - 1]) << "\n";
    }
    return 0;
}
