#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map <char,int> cnt;
    for (auto ch: s) cnt[ch]++;
    int odd = 0;
    for (auto [key, value]: cnt) odd += (value&1);
    if (odd > 1) return cout << "NO SOLUTION" << "\n", 0;
    string x = "", y = "";
    for (auto [key, value]: cnt) {
        if (value % 2 == 1) {
            while (value --) y += key;
        }
        for (int i = 1; i <= value/2; i++) x += key;
    }
    string r = x;
    reverse(r.begin(), r.end());
    cout << x + y + r << "\n";
    return 0;
}
