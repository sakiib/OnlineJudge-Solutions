#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;

const int level = 62;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif
  int n;
  LL k;
  cin >> n >> k;

  vector <int> a (n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector <vector <int> > nxt (n + 1, vector <int> (65, -1));
  for (int i = 1; i <= n; i++) nxt[i][0] = a[i];
  for (int i = 1; i <= level; i++) {
    for (int node = 1; node <= n; node++) {
      nxt[node][i] = nxt[nxt[node][i - 1]][i - 1];
    }
  }

  int cur = 1;
  for (int i = 0; i <= 62; i++) {
    if ((k >> i)&1) cur = nxt[cur][i];
  }

  cout << cur << endl;
  return 0;
}
