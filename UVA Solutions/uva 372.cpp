#include <bits/stdc++.h>
using namespace std;

#define SZ(v) (int)v.size()
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 1e9;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

vector <char> val;
vector <char> sign;
vector <char> ans;

void dfs(int x, int y) {
    if (x >= val.size()) return;
    if (x < SZ(val)) ans.push_back(val[x]);
    dfs(x + 1, y + 1);
    if (y < SZ(sign)) ans.push_back(sign[y]);
}

void solve() {
    string infix;
    while (getline(cin, infix)) {
        string prefix;
        getline(cin, prefix);

        val.clear(); sign.clear();

        for (int i = 0; i < infix.size(); i++) {
            if (isalpha(infix[i])) val.push_back(infix[i]);
        }

        for (int i = 0; i < prefix.size(); i++) {
            if (prefix[i] != ' ' && !isalpha(prefix[i])) sign.push_back(prefix[i]);
        }

        ans.clear();
        dfs(0, 0);

        cout << "INFIX => " << infix << endl;
        cout << "PREFIX => " << prefix << endl;
        cout << "POSTFIX => ";

        for (int i = 0; i < ans.size(); i++) {
            if (i == 0) cout << ans[i];
            else cout << " " << ans[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;

    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}


