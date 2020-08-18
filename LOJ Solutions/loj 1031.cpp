#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n;
int a[ 105 ];
int dp[ 105 ][ 105 ] , sum[ 105 ];

int getsum( int l , int r ) {
        if( l > r ) return 0;
        return sum[r] - sum[l-1];
}
int solve( int l , int r ) {
        if( l > r ) return 0;
        int ret = -inf;
        if( dp[l][r] != -inf ) return dp[l][r];
        for( int i = l; i <= r; i++ ) {
                ret = max( ret , getsum( l , i ) - solve( i+1 , r ) );
                ret = max( ret , getsum( i , r ) - solve( l , i -1 ) );
        }
        return dp[l][r] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d",&n);
                memset( sum , 0 , sizeof( sum ) );
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                for( int i = 1; i <= n; i++ ) sum[i] += ( sum[i-1] + a[i] );
                for( int i = 1; i <= n; i++ ) for( int j = 1; j <= n; j++ ) dp[i][j] = -inf;
                printf("Case %d: %d\n",tc,solve(1,n));
        }
        return 0;
}










