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
LL dp[ 2005 ][ 2005 ];

LL solve( LL val , LL len ) {
    if( len == k ) return 1LL;
    if( dp[ val ][ len ] != -1 ) return dp[ val ][ len ];
    LL res = 0;
    for( LL i = val ; i <= n; i += val ) {
        res = ( res%MOD + solve( i , len+1 )%MOD )%MOD;
    }
    return dp[ val ][ len ] = res%MOD;
}
int main( int argc, char const *argv[] ) {
    cin >> n >>k;
    LL ans = 0;
    memset( dp , -1 , sizeof(dp) );
    for( LL i = 1; i <= n; i++ ) {
       ans = ( ans%MOD + solve( i , 1 )%MOD )%MOD;
    }
    cout << ans << endl;
    return 0;
}

