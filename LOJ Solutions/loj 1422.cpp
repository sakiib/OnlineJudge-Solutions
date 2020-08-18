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
const int N = 1e2 + 5;

int n, a[ N ];
int dp[ N ][ N ];

int solve(int l, int r) {
  if (l == r) return 1;
  if (l > r) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  int ret = inf;
  ret = min(ret, 1 + solve(l + 1, r));
  for (int i = l + 1; i <= r; i++) {
    if (a[i] == a[l]) {
      ret = min(ret, solve(l + 1, i) + solve(i + 1, r));
    }
  }
  return dp[l][r] = ret;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t;
  scanf("%d",&t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    printf("Case %d: %d\n", tc, solve(1, n));
  }
  return 0;
}


