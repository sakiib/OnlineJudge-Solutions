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
double nextDouble() {
  double x;
  scanf("%lf",&x);
  return x;
}
int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int n = nextInt();
    vector <double> dp (n + 1, 0.0);
    for (int i = 1; i <= n; i++) dp[i] = nextDouble();
    for (int i = n - 1; i >= 1; i--) {
      int x = min(n - i, 6);
      for (int j = i + 1; j <= i + x; j++) {
        dp[i] += (dp[j]/x);
      }
    }
    printf("Case %d: %.10f\n", tc, dp[1]);
  }
  return 0;
}

