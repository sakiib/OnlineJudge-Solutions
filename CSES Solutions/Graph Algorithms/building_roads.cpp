#include <bits/stdc++.h>
using namespace std;

struct DISJOINT_SET_UNION {
    static const int MAXN = 2e5 + 5;
    int par[MAXN], sz[MAXN], compo;
    inline void makeset(int k) {
        compo = k;
        for (int i = 0; i <= k; i++) par[i] = i, sz[i] = 1;
    }
    inline int root(int x) {
        return par[x] == x ? x : par[x] = root(par[x]);
    }
    inline bool same_set(int x, int y) {
        return root(x) == root(y);
    }
    inline void unite(int x, int y) {
        int u = root(x), v = root(y);
        if (u == v) return;
        compo--;
        if (sz[v] <= sz[u]) par[v] = u, sz[u] += sz[v];
        else if (sz[v] > sz[u]) par[u] = v, sz[v] += sz[u];
    }
} dsu;

int main() {
    int n, m;
    cin >> n >> m;
    dsu.makeset(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }
    vector <int> v;
    for (int i = 1; i <= n; i++) {
        if (dsu.root(i) == i) v.push_back(i);
    }
    cout << (int)v.size() - 1 << "\n";
    for (int i = 1; i < v.size(); i++) cout << v[i - 1] << " " << v[i] << "\n";
    return 0;
}
