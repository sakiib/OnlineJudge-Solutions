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

int n , m , a , b;
int dp[ 10005 ];

int solve( int cur ) {
    if( cur >= n ) return 0;
    int mx1 = inf , mx2 = inf;
    if( dp[cur] != -1 ) return dp[cur];
    mx1 = solve( cur+1 )+a;
    mx2 = solve( cur+m )+b;
    return dp[cur] = min( mx1 , mx2 );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m >> a >> b;
    memset( dp , -1 , sizeof( dp ) );
    cout << solve( 0 ) << endl;
    return 0;
}

