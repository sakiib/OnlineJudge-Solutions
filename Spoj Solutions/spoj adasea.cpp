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
const int N = 1e3 + 5;

#define ll long long int
inline ll gcd( ll a , ll b) {
        return b == 0 ? a : gcd( b , a%b );
}
struct Fraction {
        ll n, d;
        Fraction( ) { n = 0, d = 1; }
        Fraction( ll _n, ll _d ) : n(_n), d(_d) { }
        Fraction operator+(const Fraction& p) const{
                ll g = gcd(d, p.d);
                ll td = d * (p.d / g);
                ll tn = n * (td/d) + p.n * (td/p.d);
                g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator-(const Fraction& p) const{
                ll g = gcd(d, p.d);
                ll td = d * (p.d / g);
                ll tn = n * (td/d) - p.n * (td/p.d);
                g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator*(const Fraction& p) const{
                ll g1 = gcd(n, p.d), g2 = gcd(p.n, d);
                ll tn = (n/g1) * (p.n/g2);
                ll td = (d/g2) * (p.d/g1);
                ll g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator/(const Fraction& p) const{
                ll g1 = gcd(n, p.n), g2 = (d, p.d);
                ll tn = (n/g1) * (p.d/g2);
                ll td = (d/g2) * (p.n/g1);
                ll g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        bool operator==(const Fraction& p) const{
                return n == p.n and d == p.d;
        }
        bool operator!=(const Fraction& p) const{
                return !(*this == p);
        }
        bool operator<(const Fraction& b) const {
                if(n == b.n) return d < b.d;
                return n < b.n;
        }
};

ostream& operator<<(ostream &out, Fraction p) {
        out << p.n << "/" << p.d;
}

const Fraction ONE = Fraction(1, 1);
const Fraction ZERO = Fraction(0, 1);
const Fraction NEGO = Fraction(-1, 1);

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int r, c;
string s[ N ];
bool vis[ N ][ N ];

bool inside(int nx, int ny) {
    return nx >= 0 && ny >= 0 && nx < r && ny < c;
}
int dfs(int x, int y) {
    vis[x][y] = true;
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!inside(nx, ny) || s[nx][ny] != '#') continue;
        if (vis[nx][ny]) continue;
        ret += dfs(nx, ny) + 1;
    }
    return ret;
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];
    memset(vis, false, sizeof(vis));
    Fraction EV = ZERO;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == '#' && !vis[i][j]) {
                int sz = 1 + dfs(i, j);
                EV = EV + (Fraction(sz, 1) * Fraction(sz, r * c));
            }
        }
    }

    if (EV.d == 1) cout << EV.n << endl;
    else cout << EV.n << " / " << EV.d << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}


