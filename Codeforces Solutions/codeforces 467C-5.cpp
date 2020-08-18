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

LL n , m , k;
LL ara[ N ];
LL dp[ 5005 ][ 5005 ];

LL solve( int idx , int taken ) {
    if( idx > n ) {
        if( taken == k ) return 0;
        else return -INF;
    }
    if( taken > k ) return -INF;
    if( dp[idx][taken] != -1 ) return dp[idx][taken];
    LL res1 = 0 , res2 = 0 , mx = 0;
    res1 = solve( idx+m , taken+1 )+( ara[idx]-ara[idx-m] );
    res2 = solve( idx+1 , taken );
    return dp[idx][taken] = max( res1 , res2 );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m >> k;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    for( int i = 1; i <= n; i++ ) {
        ara[i] += ara[i-1];
    }
    LL ans = 0;
    memset( dp , -1 , sizeof(dp) );
    cout << solve( 0 , 0 ) << endl;
    return 0;
}

