#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );
#define endl                   '\n'
#define ii                     pair < int, int >
#define iii                    pair < int, ii >
#define pll                    pair < LL, LL >
#define ff                     first
#define ss                     second
#define mp                     make_pair
#define pb                     push_back
#define Fix( x )               setprecision( x ) << fixed
#define MEM( a , x )           memset( a, x, sizeof( a ) )
#define ONBit( N , p )         ( N = N | ( 1 << p ) )
#define OFFBit( N , p )        ( N = N & ~( 1 << p ) )
#define CheckBit( N , p )      ( !( ( N & ( 1 << p ) ) == 0 ) )

char str[ 15 ];
int d;
int len;
LL dp[ (1 << 10) +5 ][ 10005 ];
LL fact[ 15 ];
int cnt[ 15 ];

LL solve( int mask , int val ) {

    if( mask == ( 1 << len )-1 ) {
        if( val == 0 ) return 1;
        return 0;
    }
    if( dp[mask][val] != -1 ) return dp[mask][val];
    LL ret = 0;
    for( int i = 0; i < len; i++ ) {
        if( CheckBit( mask , i ) ) continue;
        int x = str[i]-'0';
        int cur = mask;
        ret += solve( ONBit( cur , i ) , (val*10+x)%d );
    }
    return dp[mask][val] = ret;
}
void calc( ) {
    fact[0] = 1;
    for( int i = 1; i <= 10; i++ ) fact[i] = fact[i-1]*i;
}
int main( int argc , char const *argv[] ) {
    int t;
    calc( );
    scanf("%d",&t);
    while( t-- ) {
        scanf("%s %d",str,&d);
        len = strlen( str );
        memset( cnt , 0 , sizeof(cnt) );
        for( int i = 0; i < len; i++ ) cnt[ str[i]-'0' ]++;
        memset( dp , -1 , sizeof(dp) );
        LL tot = solve( 0 , 0 );
        for( int i = 0; i <= 9; i++ ) tot /= fact[ cnt[i] ];
        printf("%lld\n",tot);
    }
    return 0;
}



