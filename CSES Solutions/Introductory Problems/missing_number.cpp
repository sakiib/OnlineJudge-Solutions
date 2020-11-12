#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map <int,bool> have;
    for (int i = 1; i <= n - 1; i++) {
        int val;
        cin >> val;
        have[val] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!have.count(i)) cout << i << endl;
    }
    return 0;
}
