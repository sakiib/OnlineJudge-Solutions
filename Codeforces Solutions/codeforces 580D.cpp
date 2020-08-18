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

#define   CheckBit( N , p )      ( !( ( N & ( 1 << p ) ) == 0 ) )
#define   ONBit( N , p )         ( N = N | ( 1 << p ) )
#define   OFFBit( N , p )        ( N = N & ~( 1 << p ) )

int n , m , k;
LL val[ 19 ];
LL dp[ 1 << 19 ][ 19 ];
LL add[ 19 ][ 19 ];

LL solve( int mask , int prev ) {
    if( __builtin_popcount( mask ) == m ) return 0;
    if( dp[mask][prev] != -1 ) return dp[mask][prev];

    LL ret = 0;
    for( int i = 1; i <= n; i++ ) {
        if( CheckBit( mask , i ) ) continue;
        int cur = mask;
        ret = max( ret , solve( ( ONBit( cur , i ) ) , i )+val[i]+add[prev][i] );
    }
    return dp[mask][prev] = ret;
}
int main( int argc, char const *argv[] ) {
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&val[i]);
    memset( add , 0 , sizeof(add) );
    memset( dp , -1 , sizeof(dp) );
    for( int i = 1; i <= k; i++ ) {
        int a , p;
        LL g;
        scanf("%d %d %lld",&a,&p,&g);
        add[p][a] = g;
    }
    printf("%lld\n",solve( 0 , 0 ) );
    return 0;
}

