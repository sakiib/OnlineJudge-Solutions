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
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t;
  cin >> t;
  while (t--) {
    int n;
    double p, q;
    cin >> n >> p >> q;
    n = min(n, 10000);
    vector < vector <double> > dp(n + 1, vector <double>(2, 0.0));
    dp[0][0] = 0.0;
    dp[0][1] = 1.0;
    for (int i = 1; i <= n; i++) {
      double x;
      if (dp[i - 1][0] > dp[i - 1][1]) {
        x = (1 - p)/(1 - p * q);
      }
      else {
        x = p/(1 - (1 - p) * (1 - q));
      }
      dp[i][0] = dp[i - 1][1] * x + dp[i - 1][0] * (1 - x);

      if (dp[i - 1][0] > dp[i - 1][1]) {
        x = q * (1 - p)/(1 - p * q);
      }
      else {
        x = (1 - q) * p/(1 - (1 - p) * (1 - q));
      }
      dp[i][1] = dp[i - 1][1] * x + dp[i - 1][0] * (1 - x);
    }
    cout << setprecision(10) << fixed;
//    for (int i = 0; i <= 10; i++) {
//      cout << dp[i][0] << " " << dp[i][1] << endl;
//    }
    cout << dp[n][0] << endl;
  }
  return 0;
}

