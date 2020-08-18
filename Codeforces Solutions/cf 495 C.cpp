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

#define   CheckBit( n , b )      ( ( n >> b ) & 1 )
#define   ONBit( n , b )         ( n = n | ( 1 << b ) )
#define   OFFBit( n , b )        ( n = n & ~( 1 << b ) )

int n;
int ara[ 16 ][ 16 ];
int dp[ 1 << 16 ][ 16 ];

int solve( int id , int mask ) {
    if( id >= n ) return 0;
    if( dp[mask][id] != -1 ) return dp[mask][id];
    int ret = 0;
    for( int i = 0; i < n; i++ ) {
        if( mask&( 1 << (i) ) ) continue;
        ret = max( ret , solve( id+1 , mask|( 1 << ( i ) ) )+ara[id][i] );
    }
    dp[mask][id] = ret;
    return dp[mask][id];
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d",&n);
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                scanf("%d",&ara[i][j]);
            }
        }
        memset( dp , -1 , sizeof(dp) );
        printf("Case %d: %d\n",tc,solve( 0 , 0 ) );
    }
    return 0;
}
