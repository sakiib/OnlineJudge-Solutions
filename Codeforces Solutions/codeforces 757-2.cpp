#include <bits/stdc++.h>

using namespace std;

map<char, int> m;

int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    cout << min(m['B'], min(m['u'] / 2, min(m['l'], min(m['b'], min(m['a'] / 2, min(m['s'], m['r']))))));
    return 0;
}
