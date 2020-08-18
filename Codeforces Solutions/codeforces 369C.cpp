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

int v1 , v2 , t , d;
int dp[ 3005 ][ 1005 ];

int solve( int v , int time ) {
    if( time == t ) {
       return ( v == v2 ) ? v : -inf;
    }
    if( dp[ v+1005 ][ time ] != -1 )
    return dp[ v+1005 ][ time ];

    int mx = -inf;
    for( int i = -d; i <= d; i++ ) {
        mx = max( mx , solve( v+i , time+1 )+v );
    }
    return dp[ v+1005 ][ time ] = mx;
}
int main( int argc, char const *argv[] ) {
    cin >> v1 >> v2 >> t >> d;
    memset( dp, -1, sizeof( dp ) );
    cout << solve( v1 , 1 ) << endl;
    return 0;
}
