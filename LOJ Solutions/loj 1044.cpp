#include <bits/stdc++.h>
using namespace std;

int pal[1005][1005];
int len;
int dp[1005];
char s[1005];

int palin(int x, int y) {
  if (x >= y) return 1;
  if (pal[x][y] != -1) return pal[x][y];
  int ret = 0;
  if (s[x] != s[y]) return 0;
  else ret |= palin(x + 1, y - 1);
  return pal[x][y] = ret;
}
int solve(int x) {
  if (x >= len) return 0;
  if (palin(x, len - 1)) return 1;
  if (dp[x] != -1) return dp[x];
  int ret = 100000;
  for (int i = x; i < len; i++) {
    if (palin(x, i)) ret = min(ret, 1 + solve(i + 1));
  }
  return dp[x] = ret;
}
int main() {
  int t;
  scanf("%d",&t);
  for (int tc = 1; tc <= t; tc++) {
    scanf("%s",s);
    memset(dp, -1, sizeof(dp));
    memset(pal, -1, sizeof(pal));
    len = strlen(s);
    printf("Case %d: %d\n", tc,  solve(0));
  }
  return 0;
}






