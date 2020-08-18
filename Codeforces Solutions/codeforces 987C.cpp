#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL INF = 1e17;
const int N = 3e3 + 5;

int n;
LL c[ N ] , s[ N ], dp[ N ][ 5 ];

LL solve( int idx , int taken ) {
        if( idx > n ) return taken == 3 ? 0LL : INF;
        if( taken == 3 ) return 0LL;
        if( dp[idx][taken] != -1 ) return dp[idx][taken];
        LL ret = INF;
        for( int i = idx + 1; i <= n; i++ ) {
                 if( c[i] > c[idx] ) ret = min( ret , solve( i , taken + 1 ) + s[i] );
        }
        return dp[idx][taken] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> c[i];
        for( int i = 1; i <= n; i++ ) cin >> s[i];
        memset( dp , -1 , sizeof( dp ) );
        LL ans = solve( 0 , 0 );
        if( ans >= INF ) cout << -1 << endl;
        else cout << ans << endl;
        return 0;
}










