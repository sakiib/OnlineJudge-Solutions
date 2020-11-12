#include <bits/stdc++.h>
using namespace std;

vector <int> prefix_function(string &s) {
    int n = (int) s.size();
    vector <int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
vector <int> find_occurences(string &text, string &pattern) {
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector <int> v;
    vector <int> lps = prefix_function(cur);
    for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if (lps[i] == sz2) v.push_back(i - 2 * sz2);
    }
    return v;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector <int> occ = find_occurences(text, pattern);
    cout << (int)occ.size() << endl;
    return 0;
}
