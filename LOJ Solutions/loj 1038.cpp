#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* na, Arg1&& arg1, Args&&... args) {
    const char* c = strchr(na + 1, ',');
    cerr.write(na, c - na) << " : " << arg1 << " , ";
    __f(c + 1, args...);
}
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

vector <int> d[ N ];
double ev[ N ];

void solve() {
    int n;
    cin >> n;
    cout << setprecision(6) << fixed;
    cout << ev[n] << endl;
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i; j <= 1e5; j += i) {
            d[j].push_back(i);
        }
    }
    for (int i = 2; i <= 1e5; i++) {
        int sz = d[i].size();
        for (auto x: d[i]) {
            if (i != x) ev[i] += (1.0 * ev[x])/(sz - 1);
        }
        ev[i] += (1.0 * sz)/(sz - 1);
    }
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}


