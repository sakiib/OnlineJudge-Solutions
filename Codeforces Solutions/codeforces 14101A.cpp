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

int a , b , c;
int dp[ 105 ][ 105 ][ 105 ];

int solve( int x , int y , int z ) {
    if( dp[x][y][z] != -1 ) return dp[x][y][z];
    int op1 = 0 , op2 = 0;
    if( z > 0 && x > 1 ) op1 = solve( x-2 , y , z-1 )+1;
    if( z > 0 && y > 0 ) op2 = solve( x , y-1 , z-1 )+1;
    return dp[x][y][z] = max( op1 , op2 );
}
int main( int argc, char const *argv[] ) {
    cin >> a >> b >> c;
    memset( dp , -1 , sizeof(dp) );
    cout << solve( a , b , c ) << endl;
    return 0;
}

