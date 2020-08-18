#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 100000007;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;
#define endl "\n"
#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

struct DISCRETE_LOGARITHM_SHANKS {
        inline LL BigMod ( LL b , LL p , LL mod ) {
                LL res = 1 % mod , x = b % mod;
                while ( p ) {
                        if ( p & 1 ) res = ( res * x ) % mod;
                        x = ( x * x ) % mod; p >>= 1;
                }
                return ( res % mod );
        }
        inline LL GCD( LL a , LL b ) { return b? GCD( b , a % b ) : a; }
        inline LL Baby_Step_Giant_Step( LL a , int b , int p ) {
                a %= p , b %= p;
                if( b == 1 ) return 0;
                LL cnt = 0 , t = 1;
                for( LL g = GCD( a , p ); g != 1; g = GCD( a , p ) ) {
                        if( b % g ) return -1;
                        p /= g , b /= g , t = t * a / g % p;
                        ++cnt;
                        if( b == t ) return cnt;
                }
                map <LL,LL> Hash;
                LL m = LL( sqrt(1.0 * p) + 1 ) , base = b;
                for( int i = 0; i != m; ++i ) {
                        Hash[ base ] = i; base = base * a % p;
                }
                base = BigMod( a , m , p ); LL now = t;
                for(int i = 1; i <= m + 1; ++i) {
                        now = now * base % p;
                        if( Hash.count(now) ) return ( i * m - Hash[now] + cnt );
                }
                return -1;
        }
} dis;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                LL ans = dis.Baby_Step_Giant_Step( a , b , MOD );
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}













