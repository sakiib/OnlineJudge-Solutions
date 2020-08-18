#include <bits/stdc++.h>
using namespace std;

const int N = 705;

int dp[ N ][ N ][ 2 ];
int n , a[ N ];
vector <int> graph[ N ];

int ok( int l , int r , int left ) {
        if( l > r ) return 1;
        if( dp[l][r][left] != -1 ) return dp[l][r][left];
        int ret = 0;
        int cur = ( left == 1 ? r-1 : l+1 );
        for( auto x : graph[ cur ] ) {
                // BST property must be maintained.
                if( l <= x && x <= r && ok( l , x-1 , 1 ) && ok( x+1 , r , 0 ) ) {
                        ret = 1;
                        break;
                }
        }
        return dp[l][r][left] = ret;
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1;i <= n; i++ ) scanf("%d",&a[i]);
        for( int i = 1; i <= n; i++ ) {
                for( int j = i+1; j <= n; j++ ) {
                        if( __gcd( a[i] , a[j] ) > 1 ) {
                                graph[i].push_back( j ); graph[j].push_back( i );
                        }
                }
        }
        memset( dp , -1 , sizeof(dp) );
        for(int i = 1; i <= n; i++ ) {
                // make BST rooted at pos i
                if( ok( 1 , i-1 , 1 ) && ok( i+1 , n , 0 ) ) return printf("Yes\n"),0;
        }
        printf("No\n");
        return 0;
}






