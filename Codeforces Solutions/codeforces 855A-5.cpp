#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 5e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ N ];
bool dp[ N ][ 5 ];
LL val[ 5 ];
LL n;

LL solve( int idx , int cur ) {
    if( idx > n ) return -INF;
    if( cur == 4 ) return 0;
    if( dp[ idx ][ cur ] != -1 ) return dp[idx][cur];
    LL mx1 = -INF , mx2 = -INF;
    mx1 = solve( idx+1 , cur );
    mx2 = ara[idx]*val[cur]+solve( idx , cur+1 );
    return dp[idx][cur] = max( mx1 , mx2 );
}
int main( int argc, char const *argv[] ) {
    scanf("%lld%lld%lld%lld",&n,&val[1],&val[2],&val[3]);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    memset( dp , -1, sizeof(dp) );
    printf("%lld\n",solve( 1 , 1 ) );
    return 0;
}

