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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int n, cap;
  cin >> n >> cap;
  vector <LL> w (n + 1);
  vector <LL> v (n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  vector <vector <LL> > dp (n + 5, vector <LL> (cap + 5, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= cap; j++) {
      dp[i][j] = dp[i - 1][j];
      if (w[i] <= j) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[n][cap] << endl;
  return 0;
}
