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

LL n , k , d;
LL dp[ 105 ][ 105 ];

LL solve( LL val , LL mx ) {
    if( val > n ) return 0;
    if( val == n && mx >= d ) return 1;
    if( val == n && mx < d ) return 0;
    LL ans = 0;
    if( dp[ val ][ mx ] != -1 ) return dp[ val ][ mx ];
    for( LL i = 1; i <= k; i++ ) {
        ans = (ans%MOD + solve( val+i , max( mx , i) ))%MOD;
    }
    return dp[ val ][ mx ] = ans%MOD;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> k >> d;
    memset( dp , -1 , sizeof( dp ) );
    cout << solve( 0 , 0 ) << endl;
    return 0;
}

