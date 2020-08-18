#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL MOD = 1e9+7;
LL n , k , d;
LL dp[200][200];

LL solve( LL sum , LL mx ) {
    if( sum < 0 ) return 0;
    if( sum == 0 && mx >= d ) return 1;
    if( dp[ sum ][ mx ] != -1 ) return dp[ sum ][ mx ];
    LL ans = 0;
    for( LL i = 1; i <= k; i++ ) {
        ans += solve( sum-i , max( i, mx) );
    }
    return dp[ sum ][ mx ] = ans%MOD;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> k >> d;
    memset( dp, -1, sizeof( dp ) );
    cout<< solve( n , 0 )%MOD << endl;
    return 0;
}

