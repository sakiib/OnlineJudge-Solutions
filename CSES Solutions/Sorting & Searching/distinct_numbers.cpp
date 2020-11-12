#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> s;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        s.insert(val);
    }
    cout << (int)s.size() << endl;
    return 0;
}
