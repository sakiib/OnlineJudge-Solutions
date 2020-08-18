#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int MOD = 100000007;

LL val[ 105 ];
int n;
LL k;

LL dp[ 105 ][ 10005 ];

LL solve( int id , LL taken  ) {
    if( id > n ) return ( taken == k );
    if( taken > k ) return 0;
    if( taken == k ) return 1;
    if( dp[id][taken] != -1 ) return dp[id][taken];
    LL op1 = 0 , op2 = 0;
    for( int i = 1; i <= k; i++ ) {
        if( taken+val[id]*i <= k )
        op1 = ( op1%MOD+solve( id+1 , taken+val[id]*i )%MOD )%MOD;
    }
    op2 = ( op2%MOD+solve( id+1 , taken )%MOD )%MOD;
    return dp[id][taken] = (op1%MOD+op2%MOD)%MOD;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        memset( dp , -1 , sizeof(dp) );
        scanf("%d %lld",&n,&k);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&val[i]);
        printf("Case %d: %lld\n",tc,solve( 1 , 0 ) );
    }
    return 0;
}


