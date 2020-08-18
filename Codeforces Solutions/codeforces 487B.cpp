#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , s , l;
int a[ 2*N ] , lg[ N ];
int mx[ N ][ 30 ] , mn[ N ][ 30 ];
int ans;
int dp[ N ];

void Build_ST( ) {
    for( int i = 1; i <= n; i++ ) mx[i][0] = mn[i][0] = a[i];
    for( int i = 2; i <= n; i++ ) lg[i] = lg[i/2] + 1;
    for( int j = 1; ( 1 << j ) <= n; j++ ) {
        for( int i = 1; i+( 1 << j )-1 <= n; i++ ) {
            mn[i][j] = min( mn[i][j-1] , mn[i+( 1 << (j-1))][j-1] );
            mx[i][j] = max( mx[i][j-1] , mx[i+( 1 << (j-1))][j-1] );
        }
    }
}
pair <int,int> Query( int l , int r ) {
    if( l > r ) swap( l , r );
    int k = lg[r-l+1];
    int MN = min( mn[l][k] , mn[r-( 1 << k )+1][k] );
    int MX = max( mx[l][k] , mx[r-( 1 << k )+1][k] );
    return { MX , MN };
}
int solve( int prev ) {
        //cout <<"prev : "<< prev << endl;
        if( prev >= n ) return 0;
        if( dp[prev] != -1 ) return dp[prev];
        int ret = inf;
        for( int i = prev+l-1; i <= n; i++ ) {
                //printf("Q : %d %d\n",prev,i);
                pair <int,int> p = Query( prev , i );
                if( p.first-p.second <= s ) {
                        //printf("l = %d , r = %d\n",prev,i);
                        ret  = min( ret , 1 + solve( i+1 ) );
                }
        }
        return dp[prev] = ret;
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d %d",&n,&s,&l);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        Build_ST( );
        memset( dp , -1 , sizeof(dp) );
        int ans = solve( 1 );
        if( ans >= inf ) ans = -1;
        if( ans == 0 ) ans = 1;
        printf("%d\n",ans);
        return 0;
}






