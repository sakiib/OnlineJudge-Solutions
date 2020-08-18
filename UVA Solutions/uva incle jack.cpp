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

LL n , d;
LL dp[ 30 ][ 30 ];

LL solve( LL cur , LL give ) {
    if( give == d ) return 1;
    if( give > d ) return 0;
    LL ret = 0;
    for( int i = 0 ; i <= d; i++ ) {
        ret += solve( cur+i );
    }
    return dp[cur][give] = ret;
}
int main( int argc, char const *argv[] ) {
    while( scanf("%lld%lld",&n,&d) ) {
        if( n == 0 && d == 0 ) break;
        memset( dp , -1 , sizeof(dp) );
        LL ans = 0;
        for( int i = 0; i <= d; i++ ) {
            ans += solve( i );
        }
        printf("%lld\n",ans);
    }
    return 0;
}

