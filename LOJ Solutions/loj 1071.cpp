#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int r , c;
int a[ 105 ][ 105 ];
int dp[ 105 ][ 105 ][ 105 ][ 105 ];

int solve( int x1 , int y1 , int x2 , int y2 ) {
        if( x1 == r && y1 == c ) return 0;
        if( x2 == r && y2 == c ) return 0;
        if( x1 == x2 && y1 == y2 ) return -inf;
        if(dp[x1][y1][x2][y2] != -1 ) return dp[x1][y1][x2][y2];

}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&r,&c);
                for( int i = 1; i <= r; i++ ) {
                        for( int j = 1; j <= c; j++ ) {
                                scanf("%d",&a[i][j]);
                        }
                }
                memset( dp , -1 , sizeof( dp ) );
                int ans = solve( 1 , 2 , 2 , 1 );
                printf("Case %d: %d\n",tc,ans);
        }
        return 0;
}











