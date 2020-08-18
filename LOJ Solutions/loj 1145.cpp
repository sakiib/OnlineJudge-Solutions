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
const int mod = 100000007;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;


inline int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}

inline int add(int x, int y, int mod) {
  return x + y >= mod ? x + y - mod : x + y;
}

inline int sub(int x, int y, int mod) {
  return x - y < 0 ? x - y + mod : x - y;
}

inline int mul(int x, int y, int mod) {
  return (int)(1LL * x * y) % mod;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    int k = nextInt();
    int s = nextInt();

    vector <vector <int> > dp (2 + 1, vector <int> (max(s, k) + 1, 0));
    int id = 0;
    id = (id^1);
    for (int i = 1; i <= k; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
      id = (id^1);
      for (int j = 1; j <= s; j++) {
        dp[id][j] = add(dp[id][j - 1], dp[id ^ 1][j - 1], mod);
        dp[id][j] = sub(dp[id][j], dp[id ^ 1][max(0, j - k - 1)], mod);
      }
    }

    int ans = dp[id][s];
    printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}

