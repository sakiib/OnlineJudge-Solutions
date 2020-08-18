#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long LL;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e4 + 5;

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t;
  scanf("%d",&t);
  for (int tc = 1; tc <= t; tc++) {
    double pro;
    int n;
    scanf("%lf %d",&pro,&n);
    vector <int> a(n + 1);
    vector <double> p(n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d %lf",&a[i],&p[i]);
      p[i] = 1.0 - p[i];
      tot += a[i];
    }
    vector <double> dp(N, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = tot; j >= a[i]; j--) {
        dp[j] = max(dp[j], dp[j - a[i]] * p[i]);
      }
    }
    int ans = 0;
    for (int i = 0; i <= tot; i++) {
      if (dp[i] >= 1 - pro) ans = i;
    }
    printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}

