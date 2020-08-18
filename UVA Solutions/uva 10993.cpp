#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long LL;

LL dig;
int mod;
vector <int> v;

struct node {
  int rem;
  int taken;
  string ans;
  node (){}
  node (int rem, int taken, string ans):
    rem(rem), taken(taken), ans(ans){}
};

const int N = 1e5 + 5;
int vis[ N ][ 2 ];

string bfs() {
  queue <node> q;
  q.push(node(0, 0, ""));
  memset(vis, -1, sizeof(vis));
  while (!q.empty()) {
    node f = q.front(); q.pop();
    int rem = f.rem, len = f.taken;
    string ans = f.ans;
    if (rem == 0 && f.taken) return ans;
    for (auto x: v) {
      if (!f.taken && x == 0) continue;
      string temp = ans;
      int crem = (rem * 10 + x)%mod;
      int taken = 1;
      temp += (x + '0');
      if (vis[crem][taken] == -1 || vis[crem][taken] > vis[rem][taken] + 1) {
        vis[crem][taken] = vis[rem][taken] + 1;
        q.push(node((rem*10 + x)%mod, taken, temp));
      }
    }
  }
  return "impossible";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  while (cin >> dig >> mod) {
    if (dig == 0 && mod == 0) break;
    v.clear();
    while (dig) v.push_back(dig%10), dig /= 10;
    cout << bfs() << endl;
  }
  return 0;
}
