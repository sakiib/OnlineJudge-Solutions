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

LL ara[ N ];
LL cnt[ N ];
LL mx = 0;
LL dp[ N ];

LL solve( LL x ) {
    if( x > mx ) return 0;
    LL mx = -INF;
    if( dp[ x ] != -1 ) return dp[ x ];
    mx = max( mx , max( solve( x+1 ),solve( x+2 )+( x*cnt[x])) );
    return dp[ x ] = mx;
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        cnt [ ara[i] ]++;
        mx = max( mx , ara[i] );
    }
    memset( dp , -1 , sizeof( dp ) );
    cout << solve( 1 ) << endl;
    return 0;
}

