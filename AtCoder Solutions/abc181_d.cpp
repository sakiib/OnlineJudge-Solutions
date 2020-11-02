#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;

    if ((int)s.size() == 1) {
        if (s[0] == '8') return cout << "Yes" << endl, 0;
        return cout << "No" << endl, 0;
    }

    if ((int)s.size() == 2) {
        if (((s[0] - '0') * 10 + (s[1] - '0'))%8 == 0) return cout << "Yes" << endl, 0;
        if (((s[1] - '0') * 10 + (s[0] - '0'))%8 == 0) return cout << "Yes" << endl, 0;
        return cout << "No" << endl, 0;
    }

    map <int,int> have;
    for (int i = 0; i < s.size(); i++) {
        have[s[i] - '0']++;
    }

    for (int i = 100; i <= 999; i++) {
        if (i % 8 == 0) {
            vector <int> need (10, 0);
            int val = i;
            while (val) need[val % 10]++, val /= 10;
          	if (need[0]) continue;
            bool ok = true;
            for (int j = 1; j <= 9; j++) {
                ok &= (have[j] >= need[j]);
            }
            if (ok) return cout << "Yes" << endl, 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
