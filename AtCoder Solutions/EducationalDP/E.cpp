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
  vector <int> w (n + 1);
  vector <int> v (n + 1);
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
    tot += v[i];
  }
  vector <vector <int> > dp (n + 5, vector <int> (tot + 5, inf));
  /// dp[i][j] = minimum capacity for which we can make j for upto i'th items
  for (int i = 0; i <= n; i++) dp[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= tot; j++) {
      dp[i][j] = dp[i - 1][j];
      if (v[i] <= j) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
    }
  }
  int mx = 0;
  for (int i = 0; i <= tot; i++) {
    if (dp[n][i] <= cap) mx = i;
  }
  cout << mx << endl;
  return 0;
}
