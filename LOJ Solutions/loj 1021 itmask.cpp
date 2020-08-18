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

int base , d;
char str[ 20 ];
int len;
LL dp[ 1 << 16  ][ 21 ];

bool dig( char c ) {
    return ( c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
             c == '5' || c == '6' || c == '7' || c == '8' || c == '9' );
}
LL solve( int mask , int num ) {
    if( mask == ( 1 << len )-1 ) return ( num == 0 );
    if( dp[mask][num] != -1 ) return dp[mask][num];
    LL ret = 0;
    for( int i = 0; i < len; i++ ) {
        if( CheckBit( mask , i ) ) continue;
        int cur = mask;
        int x;
        if( dig( str[i] ) ) x = str[i]-'0';
        else x = str[i]-'A'+10;
        ret += solve( ONBit( cur , i ) , (num*base+x)%d );
    }
    return dp[mask][num] = ret;
}
int main( int argc , char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d %d",&base,&d);
        scanf("%s",str);
        len = strlen( str );
        memset( dp , -1 , sizeof(dp) );
        printf("Case %d: %lld\n",tc,solve( 0 , 0 ) );
    }
    return 0;
}
