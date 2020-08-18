#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5 + 5;

inline int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}

void solve(int tc) {
  printf("Case %d: ", tc);
  int n = nextInt();
  vector <int> a (n + 1);
  for (int i = 1; i <= n; i++) a[i] = nextInt();
  bool all_negative = true;
  for (int i = 1; i <= n; i++) {
    all_negative &= (a[i] < 0);
  }
  if (all_negative) {
    printf("inf\n");
    return;
  }

  int neg = 0, pos = 0, nsum = 0, psum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) neg++, nsum += abs(a[i]);
    else pos++, psum += a[i];
  }

  int x = psum + nsum, y = n - neg;
  int g = __gcd(x, y);
  x /= g, y /= g;

  printf("%d/%d\n", x, y);
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) solve(tc);
  return 0;
}

