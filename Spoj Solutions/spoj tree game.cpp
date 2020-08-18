#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1005;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
vector <int> graph[ N ];

vector <int> prime;
vector <bool> isprime( N , true );

void sieve( ) {
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
vector <int> PrimeFact( int n ) {
        vector <int> ret;
        int sq = sqrt( n );
        for( int i = 0; i < prime.size() && prime[i] <= sq; i++ ) {
                if( n%prime[i] == 0 ) {
                        ret.push_back( prime[i] );
                        n /= prime[i];
                        while( n%prime[i] == 0 ) {
                                ret.push_back( prime[i] );
                                n /= prime[i];
                        }
                        sq = sqrt( n );
                }
        }
        if( n > 1 ) ret.push_back( n );
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        sieve( );
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        vector <int> p = PrimeFact( n );
        LL ans = 1;
        for( auto x : p ) ans *= x;
        cout << ans << endl;
        return 0;
}











