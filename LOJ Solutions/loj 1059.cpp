#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

int nextInt() {
  int x;
  scanf("%d",&x);
  return x;
}
long long nextLong() {
  long long x;
  scanf("%lld",&x);
  return x;
}

struct data {
  int u, v, w;
  data(){}
  data(int u, int v, int w): u(u), v(v), w(w){}
  bool operator <(const data &q) {
    return w < q.w;
  }
};

template <typename T>
class dsu {
public:
  T compo;
  vector <T> p;
  vector <T> sz;
  dsu(T mx) {
    compo = mx;
    p.resize(mx + 5, 0);
    sz.resize(mx + 5, 0);
  }
  inline void make() {
    for (T i = 1; i <= compo; i++) {
      p[i] = i, sz[i] = 1;
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
    if (u != v) {
      compo--;
      if (rand()%2) p[u] = v, sz[v] += sz[u];
      else p[v] = u, sz[u] += sz[v];
    }
  }
};

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    int m = nextInt();
    int cost = nextInt();
    vector <data> edge;
    for (int i = 1; i <= m; i++) {
      int u = nextInt();
      int v = nextInt();
      int w = nextInt();
      edge.push_back(data(u, v, w));
    }
    sort(edge.begin(), edge.end());
    dsu <int> ds(n);
    ds.make();
    int ans = 0;
    for (auto x: edge) {
      if (!ds.same(x.u, x.v) && x.w < cost) {
        ds.unite(x.u, x.v);
        ans += x.w;
      }
    }
    int air = 0;
    for (int i = 1; i <= n; i++) {
      if (ds.root(i) == i) air++, ans += cost;
    }
    printf("Case %d: %d %d\n", tc, ans, air);
  }
  return 0;
}

