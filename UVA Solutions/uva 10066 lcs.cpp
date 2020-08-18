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

int a[ 105 ] , b[ 105 ];
int n , m;
int dp[ 105 ][ 105 ];

int solve( int x , int y ) {
    if( x > n || y > m ) return 0;
    if( dp[x][y] != -1 ) return dp[x][y];
    int ans = 0;
    if( a[x] == b[y] ) {
        ans = 1+solve( x+1 , y+1 );
    }
    else {
        int op1 = 0 , op2 = 0;
        op1 = solve( x+1 , y );
        op2 = solve( x , y+1 );
        ans = max( op1 , op2 );
    }
    return dp[x][y] = ans;
}
void PrintSolution( int x , int y ) {
    if( x > n || y > m ) return;
    if( a[x] == b[y] ) {
        printf("%d ",a[x]);
        PrintSolution( x+1 , y+1 );
    }
    else {
        if( dp[x+1][y] > dp[x][y+1] ) PrintSolution( x+1 , y );
        else PrintSolution( x , y+1 );
    }
}
int main( int argc, char const *argv[] ) {
    int tc = 1;
    while( scanf("%d %d",&n,&m) ) {
        if( n == 0  && m == 0 ) break;
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= m; i++ ) scanf("%d",&b[i]);
        memset( dp , -1 , sizeof(dp) );
        printf("Twin Towers #%d\n",tc++);
        printf("Number of Tiles : %d\n\n",solve( 1 , 1 ) );

        //PrintSolution( 1 , 1 );
        //printf("\n");
    }
    return 0;
}



