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
const int N = 2e5 + 5;

vector <int> prime;
vector <bool> isprime( N , true );

inline void sieve( ) {
        isprime[0] = isprime[1] = false;
        prime.push_back( 2 );
        for( int i = 4; i <= N; i +=2 ) isprime[i] = false;
        int sq = sqrt( N );
        for( int i = 3; i <= sq; i += 2 ) {
                if( isprime[i] ) {
                        for( int j = i*i; j <= N; j += 2*i ) {
                                isprime[j] = false;
                        }
                }
        }
        for( int i = 3; i <= N; i += 2 ) {
                if( isprime[i] ) prime.push_back( i );
        }
}

inline vector <LL> PrimeFact( LL n ) {
        vector <LL> ret;
        LL sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        LL cur = prime[i];
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                cur *= prime[i];
                                n /= prime[i];
                        }
                        ret.push_back(cur);
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( n );
        return ret;
}

void solve() {
    LL n;
    int tc = 0;
    while (cin >> n) {
        if (n == 0) break;
        if (n == 1) {
            cout << "Case " << ++tc << ": " << 2 << endl;
            continue;
        }
        vector <LL> v = PrimeFact(n);
        LL ans = 0;
        for (auto x: v) ans += x;
        if ((int)v.size() == 1) ans++;
        cout << "Case " << ++tc << ": " << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1;
    sieve();
    for (int tc = 1; tc <= t; tc++) solve();
    return 0;
}


