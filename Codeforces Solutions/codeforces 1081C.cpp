#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 2005;
const int MOD = 998244353;

int n , m , k;
LL dp[ N ][ N ];

LL solve( int idx , int cnt ) {
        //if( cnt > k ) return 0;
        if( idx > n ) return cnt == k;
        if( dp[idx][cnt] != -1 ) return dp[idx][cnt];
        LL ret = 0 , res = 0;
        ret = solve( idx + 1 , cnt );
        res = ( res%MOD + ret%MOD )%MOD;

        ret = solve( idx + 1 , cnt + 1 ) * ( m - 1 );
        ret = ret % MOD;
        res = ( res%MOD + ret%MOD )%MOD;

        return dp[idx][cnt] = res%MOD;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m >> k;
        memset( dp , -1 , sizeof( dp ) );
        LL ans = solve( 1 , 0 )%MOD;
        cout << ( ans%MOD * m%MOD )%MOD << endl;
        return 0;
}










