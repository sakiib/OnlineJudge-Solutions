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

int n , m;
int mn = inf;
int dp[ N ];

int solve( int pos ) {
    if( pos > n ) return inf;
    if( pos == n ) return 1;
    if( dp[pos] != -1 ) return dp[pos];
    int op = 0;
    op = solve( pos+1 )+solve( pos+2 );
    mn = min( mn , op );
    return dp[pos] = mn;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m;
    memset( dp , -1 , sizeof(dp) );
    int ans = solve( 0 );
    cout << ( ans >= inf ? -1 : ans ) << endl;
    return 0;
}

