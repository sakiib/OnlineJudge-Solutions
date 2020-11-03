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
const int N = 2e5 + 5;

void solve() {
  int n;
  cin >> n;

  vector <LL> a (n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  LL ans = 0;
  map <LL,int> have;

  for (int i = 1; i <= n; i++) {
    if (have.count(i - a[i])) ans += have[i - a[i]];
    have[i + a[i]]++;
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
