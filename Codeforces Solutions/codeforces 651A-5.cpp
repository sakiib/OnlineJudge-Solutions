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

int dp[1000][1000];

int solve( int x , int y ) {
    if( x <= 1 && y <= 1 ) return 0;
    if( x <= 0 || y <= 0 ) return 0;
    if( dp[x][y] != -1 ) return dp[x][y];
    int mx1 = 0 , mx2 = 0;
    mx1 = solve( x+1 , y-2 )+1;
    mx2 = solve( x-2 , y+1 )+1;
    return dp[x][y] = max( mx1 , mx2 );
}
int main( int argc, char const *argv[] ) {
    int x , y;
    cin >> x >> y;
    memset( dp , -1 , sizeof( dp ) );
    cout << solve( x , y ) << endl;
    return 0;
}

