#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n , m;
int a[ N ][ N] , dp[ 5 ][ N ][ N ];

void calc( ) {
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        dp[1][i][j] = max( dp[1][i-1][j] , dp[1][i][j-1] ) + a[i][j];
                }
        }
        for( int i = n; i >= 1; i-- ) {
                for( int j = m; j >= 1; j-- ) {
                        dp[2][i][j] = max( dp[2][i+1][j] , dp[2][i][j+1] ) + a[i][j];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = m; j >= 1; j-- ) {
                        dp[3][i][j] = max( dp[3][i-1][j] , dp[3][i][j+1] ) + a[i][j];
                }
        }
        for( int i = n; i >= 1; i-- ) {
                for( int j = 1; j <= m; j++ ) {
                        dp[4][i][j] = max( dp[4][i][j-1] , dp[4][i+1][j] ) + a[i][j];
                }
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= m; j++ ) {
                        scanf("%d",&a[i][j]);
                }
        }
        calc( );
        int mx = 0;
        for( int i = 2; i < n; i++ ) {
                for( int j = 2; j < m; j++ ) {
                       int x = dp[1][i][j-1] + dp[2][i][j+1] + dp[3][i-1][j] + dp[4][i+1][j];
                       int y = dp[1][i-1][j] + dp[2][i+1][j] + dp[4][i][j-1] + dp[3][i][j+1];
                       mx = max( mx , max( x , y ) );
                }
        }
        printf("%d\n",mx);
        return 0;
}

/**
3 3
100 100 100
100 1 100
100 100 100
*/









