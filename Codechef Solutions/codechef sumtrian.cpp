#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );


int n;
int val[ 105 ][ 105 ];
int dp[ 105 ][ 105 ];

bool valid( int x , int y ) {
    if( y > x ) return false;
    if( x > n ) return false;
    if( y > n ) return false;
    return true;
}
int solve( int x , int y ) {
    if( !valid( x , y ) ) return 0;
    if( x > n ) return false;
    // cout << x << " " << y << endl;
    int a = 0 , b = 0;
    if( dp[x][y] != -1 ) return dp[x][y];
    a = solve( x+1 , y )+val[x][y];
    b = solve( x+1 , y+1 )+val[x][y];
    return dp[x][y] = max( a , b );
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> n;
        memset( val , 0 , sizeof(val) );
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= i; j++ ) {
                cin >> val[i][j];
            }
        }
        memset( dp , -1 , sizeof(dp) );
        cout << solve( 1 , 1 ) << endl;
    }
    return 0;
}


