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
  string a, b;
  cin >> a >> b;
  a = "#" + a;
  b = "@" + b;
  int la = a.size();
  int lb = b.size();
  /// dp[i][j] = lcs upto i'th posisiton of string a & j'th position of string b;
  vector <vector <int> > dp (la + 5, vector <int> (lb + 5, 0));
  vector <vector <int> > path(la + 5, vector <int> (lb + 5, 0));
  for (int i = 1; i < la; i++) {
    for (int j = 1; j < lb; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
        path[i][j] = path[i - 1][j - 1];
      }
      else {
        if (dp[i][j - 1] >= dp[i - 1][j]) {
          dp[i][j] = dp[i][j - 1];
          path[i][j] = path[i][j - 1];
        }
        else {
          dp[i][j] = dp[i - 1][j];
          path[i][j] = path[i - 1][j];
        }
      }
    }
  }
  /// cout << dp[la - 1][lb - 1] << endl;
  int mx = dp[la - 1][lb - 1];
  string ans = "";
  int cur = 0;
  for (int i = la - 1; i >= 1; i--) {
    for (int j = lb - 1; j >= 1; j--) {
      if (a[i] == b[j] && cur + dp[i][j] == mx) {
        ans += a[i];
        cur ++;
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
