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
const LL INF = 1e16;
const int N = 2e5 + 5;


struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
    chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

unordered_map <int,LL,custom_hash> dp[ N ];
int n;
LL a[ N ];

LL solve(int idx, int taken) {
  int need = n/2 - (n - idx + 1)/2;
  if (taken < need) return -INF;
  if (idx >= n) return taken == n/2 ? 0 : -INF;
  if (dp[idx].count(taken)) return dp[idx][taken];
  LL ret = -INF;
  ret = max(ret, solve(idx + 2, taken + 1) + a[idx]);
  ret = max(ret, solve(idx + 1, taken));
  return dp[idx][taken] = ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << solve(0, 0) << endl;
  return 0;
}
