#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> d ((int)1e6 + 1, 0);
    for (int i = 1; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j += i) {
            d[j]++;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << d[x] << "\n";
    }
    return 0;
}
