#include <bits/stdc++.h>
using namespace std;

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

inline int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}

inline void nextString(char *x) {
  scanf("%s", x);
}

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

char s[ 20 ][ 20 ];
int sz, sx, sy;
vector <pair <int,int> > g;
int dp[15][(1 << 15) + 1];

int dist(int x1, int y1, int x2, int y2) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int mn = min(dx, dy);
  int mx = max(dx, dy);
  int diagonalSteps = mn;
  int straightSteps = mx - mn;
  return diagonalSteps + straightSteps;
}

int solve(int prev, int mask) {
  if (mask == (1 << sz) - 1) {
    return dist(g[prev].first, g[prev].second, sx, sy);
  }
  if (dp[prev][mask] != -1) return dp[prev][mask];
  int ret = inf;
  for (int idx = 0; idx < sz; idx++) {
    if (!Check(mask, idx)) {
      if (mask == 0) {
        ret = min(ret, solve(idx, Set(mask, idx)) +
              dist(g[idx].first, g[idx].second, sx, sy));
      }
      else {
        ret = min(ret, solve(idx, Set(mask, idx)) +
              dist(g[idx].first, g[idx].second, g[prev].first, g[prev].second));
      }
    }
  }
  return dp[prev][mask] = ret;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  int t = nextInt();
  for (int tc = 1; tc <= t; tc++) {
    int r = nextInt();
    int c = nextInt();
    for (int i = 0; i < r; i++) nextString(s[i]);

    g.clear();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (s[i][j] == 'x') sx = i, sy = j;
        if (s[i][j] == 'g') g.push_back(make_pair(i, j));
      }
    }
    sz = g.size();
    memset(dp, -1, sizeof(dp));
    if (sz == 0) printf("Case %d: 0\n", tc);
    else printf("Case %d: %d\n", tc, solve(0, 0));
  }
  return 0;
}

