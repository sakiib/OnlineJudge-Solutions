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
const int N = 2e5 + 5;
 
int a[ N ], b[ N ], c[ N ];
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
 
    vector <int> both, alice, bob;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1 && c[i] == 1) both.push_back(a[i]);
        if (b[i] == 1 && c[i] == 0) alice.push_back(a[i]);
        if (b[i] == 0 && c[i] == 1) bob.push_back(a[i]);
    }
 
    sort(ALL(both)); sort(ALL(alice)); sort(ALL(bob));
    int x = 0, y = 0, z = 0;
 
    int cost = 0;
    for (int i = 1; i <= k; i++) {
        if (x < SZ(both) && y < SZ(alice) && z < SZ(bob)) {
            if (both[x] <= alice[y] + bob[z]) cost += both[x], x++;
            else cost += alice[y] + bob[z], y++, z++;
        }
        else if (x < SZ(both) && (y >= SZ(alice) || z >= SZ(bob))) {
            cost += both[x], x++;
        }
        else {
            if (y < SZ(alice) && z < SZ(bob)) cost += alice[y] + bob[z], y++, z++;
            else { cout << -1 << endl; return; }
        }
    }
 
    cout << cost << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
 
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}
 