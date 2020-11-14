#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mx = 0;
    for (int i = 0; i < s.size(); i += 0) {
        int j = i;
        while (j < s.size() && s[j] == s[i]) j++;
        mx = max(mx, j - i);
        i = j;
    }
    cout << mx << endl;
    return 0;
}
