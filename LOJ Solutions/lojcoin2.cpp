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

LL n , k;
LL ans[ N ] , coin[ N ];
LL dp[ 105 ][ 1005 ];

LL solve( int idx , LL tot ) {
    if( tot == 0 ) return 1;
    if( idx > n ) return 1;
    if( dp[idx][tot] != -1 ) return dp[idx][tot];
    LL ret1 = 0 , ret2 = 0;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= k; j++ ) {
            if( tot-coin[i] >= 0 ) {
                ret1 = solve( i+1 , tot-coin[i] )+1;
                ret2 = solve( i , tot-coin[i] )+1;
            }
        }
    }
    return dp[idx][tot] = (ret1%MOD+ret2%MOD)%MOD;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%lld%lld",&n,&k);
        for( int i = 1; i <= n; i++ ) {
            scanf("%lld",&coin[i]);
        }
        memset( dp , -1 , sizeof(dp) );
        printf("Case %d: %lld\n",tc,solve( 1 , k ) );
    }
    return 0;
}

