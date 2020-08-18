#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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
const int N = 1e7 + 5;

struct primality_test {
  static const int MAXP = 1000010;
  vector <int> BASE = {2, 450775, 1795265022, 9780504, 28178, 9375, 325};
  long long seq[MAXP];
  int primes[MAXP], spf[MAXP];
  unsigned long long gcd(unsigned long long u, unsigned long long v){
    if (!u) return v;
    if (!v) return u;
    if (u == 1 || v == 1) return 1;
    int shift = __builtin_ctzll(u | v);
    u >>= __builtin_ctzll(u);
    do{
      v >>= __builtin_ctzll(v);
      if (u > v) v ^= u ^= v ^= u;
      v = v - u;
    } while (v);
    return u << shift;
  }
  inline long long mod_add(long long x, long long y, long long m){
    return (x += y) < m ? x : x - m;
  }
  inline long long mod_mul(long long x, long long y, long long m){
    long long res = x * y - (long long)((long double)x * y / m + 0.5) * m;
    return res < 0 ? res + m : res;
  }
  inline long long mod_pow(long long x, long long n, long long m){
    long long res = 1 % m;
    for (; n; n >>= 1){
      if (n & 1) res = mod_mul(res, x, m); x = mod_mul(x, x, m);
    }
    return res;
  }
  inline bool miller_rabin(long long n){
    if (n <= 2 || (n & 1 ^ 1)) return (n == 2);
    if (n < MAXP) return spf[n] == n;
    long long c, d, s = 0, r = n - 1;
    for (; !(r & 1); r >>= 1, s++) {}
    for (int i = 0; i < 2; i++){
      c = mod_pow(BASE[i], r, n);
      for (int j = 0; j < s; j++){
        d = mod_mul(c, c, n);
        if (d == 1 && c != 1 && c != (n - 1)) return false;
        c = d;
      }
      if (c != 1) return false;
    }
    return true;
  }
  inline void init(){
    int i, j, k, cnt = 0;
    for (i = 2; i < MAXP; i++){
      if (!spf[i]) primes[cnt++] = spf[i] = i;
      for (j = 0, k; (k = i * primes[j]) < MAXP; j++){
        spf[k] = primes[j]; if(spf[i] == spf[k]) break;
      }
    }
  }
} miller;

vector <int> prime;
vector <bool> isprime(N, true);
int nxt[ N ];

void sieve() {
  isprime[0] = isprime[1] = false;
  prime.push_back(2);
  for (int i = 4; i <= N; i += 2) isprime[i] = false;
  int sq = sqrt(N);
  for (int i = 3; i <= sq; i += 2) {
    if (isprime[i]) {
      for (int j = i * i; j <= N; j += 2 * i) {
        isprime[j] = false;
      }
    }
  }
  for (int i = 3; i <= N; i += 2) {
    if (isprime[i]) {
      nxt[prime.back()] = i; prime.push_back(i);
    }
  }
}

inline LL nextPrime(LL n){
  if (n <= 1e7 && nxt[n] != 0) return nxt[n];
  for (n = (n + 1) / 2 * 2 + 1; !miller.miller_rabin(n); n += 2);
  return n;
}

vector <int> num;

int sz;
int dp[ 25 ];

int solve(int idx) {
  if (idx >= sz) return 0;
  if (dp[idx] != -1) return dp[idx];
  int ret = -100;
  LL val = 0;
  for (int i = idx; i < sz; i++) {
    if (val == 0 && num[i] == 0) return -100;
    val = val * 10 + num[i];
    if (miller.miller_rabin(val)) ret = max(ret, solve(i + 1) + 1);
  }
  return dp[idx] = ret;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL
  miller.init();
  sieve();
  int t;
  scanf("%d",&t);
  while (t--) {
    LL n;
    scanf("%lld",&n);
    LL ans = -1;
    while (1) {
      num.clear();
      LL temp = n;
      while (temp) num.push_back(temp%10), temp /= 10;
      sz = num.size();
      reverse(num.begin(), num.end());
      memset(dp, -1, sizeof(dp));
      int mx = solve(0);
      if (mx > 1 && miller.miller_rabin(n)) { ans = n; break; }
      n = nextPrime(n);
    }
    assert(ans != -1);
    printf("%lld\n", ans);
  }
  return 0;
}

