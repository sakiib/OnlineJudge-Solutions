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
  scanf("%d", &x);
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    vector <int> a (n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = nextInt();
      tot += a[i];
    }
    tot /= 2;
    int offset = tot;

    vector <vector <int> > dp (2, vector <int> (tot + offset + 1, -inf));

    int id = 0;
    dp[id][0 + offset] = 0;

    for (int i = 1; i <= n; i++) {
      id = (id^1);
      for (int j = -tot; j <= tot; j++) {
        dp[id][j + offset] = dp[id ^ 1][j + offset];
        if (j + a[i] + offset <= tot + offset) {
          dp[id][j + offset] = max(dp[id][j + offset], dp[id ^ 1][j + a[i] + offset] + a[i]);
        }
        if (j - a[i] + offset >= 0) {
          dp[id][j + offset] = max(dp[id][j + offset], dp[id ^ 1][j - a[i] + offset]);
        }
      }
    }
    int ans = max(0, dp[id][0 + offset]);
    if (ans == 0) printf("Case %d: impossible\n", tc);
    else printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}


