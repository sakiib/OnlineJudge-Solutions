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
#define endl "\n"
#define all(v) v.begin(), v.end()
#define UNIQUE(v) sort(all(v)),v.erase(unique(all(v)),v.end())
typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

int nextInt() {
  int x;
  scanf("%d",&x);
  return x;
}

int a[ N ];

template <typename T> class dsu {
public:
  T com; vector <T> p, sz, mon;
  dsu(T mx) {
    com = mx;
    p.resize(mx + 5, 0); sz.resize(mx + 5, 0);
    mon.resize(mx + 5, 0);
  }
  inline void build() {
    for (T i = 1; i <= com; i++) {
      p[i] = i, sz[i] = 1, mon[i] = a[i];
    }
  }
  inline T root(T x) {
    return p[x] == x ? x : p[x] = root(p[x]);
  }
  inline bool same(T x, T y) {
    return root(x) == root(y);
  }
  inline void unite(T x, T y) {
    T u = root(x), v = root(y);
    if (u == v) return;
    com--;
    p[u] = v, sz[v] += sz[u], mon[v] += mon[u];
  }
};

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    int m = nextInt();
    for (int i = 1; i <= n; i++) {
      a[i] = nextInt();
    }
    dsu <LL> ds(n);
    ds.build();
    for (int i = 1; i <= m; i++) {
      int u = nextInt();
      int v = nextInt();
      ds.unite(u, v);
    }
    bool f = true;
    set <LL> s;
    for (int i = 1; i <= n; i++) {
      if (ds.root(i) == i) {
        LL tot = ds.mon[ds.root(i)];
        LL person = ds.sz[ds.root(i)];
        if (tot%person != 0) f = false;
        else s.insert(tot/person);
      }
    }
    if (f && (int)s.size() == 1) printf("Case %d: Yes\n", tc);
    else printf("Case %d: No\n",tc);
  }
  return 0;
}

