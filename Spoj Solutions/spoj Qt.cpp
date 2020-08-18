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

int x , y;
int mx = 0;
LL dp[ 105 ][ 105 ];

int solve( int num , int taken ) {
    if( taken > y ) return 0;
    if( num < 0 ) return 0;
    if( num == 0 ) {
        if( taken == y ) return 1;
        else return 0;
    }
    if( dp[num][taken] != -1 ) return dp[num][taken];
    LL ret = 0;
    for( LL i = x; i >= 1; i-- ) {
        if( num-i >= 0 ) {
            ret = max( ret , solve( num-i , taken+1 )*i );
        }
    }
    return dp[num][taken] = ret;
}
int main( int argc, char const *argv[] ) {
    cin >> x >> y;
    memset( dp , -1 , sizeof(dp) );
    cout << solve( x , 0 ) << endl;;
    return 0;
}
