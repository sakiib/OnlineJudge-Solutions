#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

vector <bool> isprime( 100*N , true );
vector <LL> prime;
LL n;

inline void sieve( ) {
    isprime[0] = isprime[1] = false;
    for( LL i = 4; i <= 100*N; i += 2 ) isprime[i] = false;
    prime.push_back( 2 );
    LL sq = sqrt( 100*N );
    for( LL i = 3; i <= sq; i += 2 ) {
        if( isprime[i] ) {
            for( LL j = i*i; j <= 100*N; j += 2*i ) {
                isprime[j] = false;
            }
        }
    }
    for( LL i = 3; i <= 100*N; i += 2 ) {
        if( isprime[i] ) prime.push_back( i );
    }
}
inline LL BigMod ( LL a , LL p , LL m ) {
    LL res = 1%m , x = a%m;
    while( p ) {
        if( p&1 ) res = ( res*x )%m;
        x = ( x*x )%m;
        p >>= 1;
    }
    return res;
}
inline LL get_ans( LL n ) {
    LL ret = 1LL;
    for( int i = 0; i < prime.size() && prime[i] <= n; i++ ) {
        LL occur = 0 , num = prime[i];
        for( LL val = prime[i]; val <= n; val *= prime[i] ) {
            occur += n/val;
        }
        if( occur&1 ) --occur;
        ret = (ret%MOD * BigMod( num , occur , MOD )%MOD)%MOD;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    sieve( );
    while( scanf("%lld",&n) ) {
        if( n == 0 ) break;
        LL ans =  get_ans( n );
        printf("%lld\n",ans);
    }
    return 0;
}

