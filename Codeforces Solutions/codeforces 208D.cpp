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
const int N = 50 + 5;

int p[ N ], a[ N ], mx[ N ];
bool done[ N ];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) mx[a[i]] = max(mx[a[i]], p[i]);

    int ans = 0;

    for (int i = 1; i <= k; i++) {
        int id;
        cin >> id;
        for (int j = 1; j <= n; j++) {
            if (j == id) continue;
            if (a[j] == id && p[j] > p[id]) ans++;
        }
    }

    cout << ans << endl;
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


