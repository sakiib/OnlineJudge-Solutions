#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
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

template <typename T> class segment_tree {
public:
  vector <T> tree;
  static const T def = 0;
  segment_tree(int sz) {
    tree.resize(4 * sz + 5, 0);
  }
  inline void update(int node, int b, int e, int p, T v) {
    if (p > e || p < b || b > e) return;
    if (b == e && b == p) {
      tree[node] = v;
      return;
    }
    int l = node << 1, r = l | 1, m = (b + e) >> 1;
    update(l, b, m, p, v);
    update(r, m + 1, e, p, v);
    tree[node] = max(tree[l], tree[r]);
  }
  inline T query(int node, int b, int e, int i, int j) {
    if (i > e || j < b || b > e) return def;
    if (i <= b && j >= e) return tree[node];
    int l = node << 1, r = l | 1, m = (b + e) >> 1;
    return max(query(l, b, m, i, j), query(r, m + 1, e, i, j));
  }
};

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = nextInt();
    map <int,int> have;
    for (int i = 1; i <= n; i++) have[a[i]]++;
    int id = 0;
    map <int,int> ID;
    for (auto x: have) ID[x.first] = ++id;
    for (int i = 1; i <= n; i++) a[i] = ID[a[i]];
    vector <int> l(n + 1, 0);
    vector <int> r(n + 1, 0);
    segment_tree <int> L(n);
    segment_tree <int> R(n);
    for (int i = 1; i <= n; i++) {
      int best = L.query(1, 1, n, 1, a[i] - 1);
      l[i] = best + 1;
      L.update(1, 1, n, a[i], l[i]);
    }
    for (int i = n; i >= 1; i--) {
      int best = R.query(1, 1, n, 1, a[i] - 1);
      r[i] = best + 1;
      R.update(1, 1, n, a[i], r[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, 2 * min(l[i], r[i]) - 1);
    }
    printf("Case %d: %d\n",tc, ans);
  }
  return 0;
}

