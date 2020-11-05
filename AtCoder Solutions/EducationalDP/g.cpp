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

struct directed_graph {
  static const int N = 1e5 + 5;
  struct data {
    int node; int val;
    data() : node(-1), val(-1) {}
    data(int node, int val) : node(node), val(val){}
  };
  int n; int ind[ N ]; vector <data> g[ N ];
  void init(int _n){
    n = _n;
    for (int i = 0; i <= n; i++) ind[i] = 0, g[i].clear();
  }
  void add_edge(int u, int v, int val = 0) {
    g[u].push_back(data(v, val)); ind[v]++;
  }
  vector <int> topological_order() {
    queue <int> q;
    for (int i = 1; i <= n; i++) if (ind[i] == 0) q.push(i);
    vector <int> ans;
    while (!q.empty()) {
      int to = q.front(); q.pop(); ans.push_back(to);
      for (auto x : g[to]) {
        ind[x.node]--;
        if (ind[x.node] == 0) q.push(x.node);
      }
    }
    if ((int)ans.size() != n) return vector <int> {}; return ans;
  }
} g;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int n, e;
  cin >> n >> e;
  g.init(n);
  for (int i = 1; i <= e; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(u, v, 1);
  }
  vector <int> t = g.topological_order();
  vector <int> path(n + 1, 0);
  for (auto x: t) {
    for (auto val: g.g[x]) {
      path[val.node] = path[x] + 1;
    }
  }
  int mx = 0;
  for (auto x: t) mx = max(mx, path[x]);
  cout << mx << endl;
  return 0;
}
