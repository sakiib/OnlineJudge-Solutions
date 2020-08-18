#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
LL ara[ N ] , cnt[ N ];
LL dp[ N ];
LL mx = -1000000;

LL solve( LL num ) {
    if( num > mx ) return 0;
    if( dp[num] != -1 ) return dp[num];
    LL op1 = solve( num+2 )+cnt[num]*num;
    LL op2 = solve( num+1 );
    return dp[num] = max( op1, op2 );
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        cnt[ ara[i] ]++;
        mx = max( mx, ara[i] );
    }
    memset( dp, -1, sizeof(dp) );
    printf("%lld\n",solve( 1 ));
    return 0;
}
