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
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e6 + 5;

int p[ N ][ 2 ];
const int mod[] = {1000000000 + 7, 1000000000 + 9};
const int base[] = {29, 37};

inline int add(int x, int y, int mod) {
  return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y, int mod) {
  return x - y < 0 ? x - y + mod : x - y;
}
inline int mul(int x, int y, int mod) {
  return (1LL * x * y) % mod;
}
LL combine(LL x, LL y) {
  return (x << 31LL)|y;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  p[0][0] = 1, p[0][1] = 1;
  for (int i = 1; i <= 1e6; i++) {
    for (int j = 0; j <= 1; j++) {
      p[i][j] = mul(p[i - 1][j], base[j], mod[j]);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string x = "", y = "";
    int l = 0, r = s.size() - 1;
    while (l < r && s[l] == s[r]) {
      x += s[l], y += s[r], l++, r--;
    }
    if (l == r) {
      cout << x;
      cout << s[l];
      reverse(y.begin(), y.end());
      cout << y << endl;
      continue;
    }
    string rem = s.substr(l, r - l + 1);
    vector <int> f(2, 0);
    vector <int> b(2, 0);
    int len = 0;
    for (int i = 0; i < rem.size(); i++) {
      for (int j = 0; j <= 1; j++) {
        f[j] = add(f[j], mul(p[i][j], rem[i], mod[j]), mod[j]);
        b[j] = mul(b[j], base[j], mod[j]);
        b[j] = add(b[j], rem[i], mod[j]);
      }
      if (combine(f[0], f[1]) == combine(b[0], b[1])) len = i + 1;
    }
    string L = rem.substr(0, len);
    len = 0;
    int sz = rem.size();
    f[0] = 0, f[1] = 0, b[0] = 0, b[1] = 0;
    len = 0;
    for (int i = sz - 1, k = 0; i >= 0; i--, k++) {
      for (int j = 0; j <= 1; j++) {
        f[j] = add(f[j], mul(p[k][j], rem[i], mod[j]), mod[j]);
        b[j] = mul(b[j], base[j], mod[j]);
        b[j] = add(b[j], rem[i], mod[j]);
      }
      if (combine(f[0], f[1]) == combine(b[0], b[1])) len = sz - i;
    }
    string R = rem.substr(sz - len, len);
    if ((int)L.size() >= (int)R.size()) {
      cout << x;
      cout << L;
      reverse(y.begin(), y.end());
      cout << y << endl;
    }
    else {
      cout << x;
      cout << R;
      reverse(y.begin(), y.end());
      cout << y << endl;
    }
  }
  return 0;
}

