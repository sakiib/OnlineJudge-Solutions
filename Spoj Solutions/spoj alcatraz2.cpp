#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int Set( int N , int pos )    { return N = N | ( 1 << pos ); }
int Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos ) { return (bool)( N & ( 1 << pos ) ); }

int ara[ 10 ];
int n;
vector < int > graph[ 10 ];
int dp[ 1 << 8 +2 ];

int solve( int mask ) {
    int ret = 0;
    if( mask == ( 1 << 8 )-1 ) return 0;
    if( dp[mask] != -1 ) return dp[mask];
    for( int i = 1; i <= 8; i++ ) {
        if( !Check( mask , i-1 ) ) {
           int newmask = mask;
           newmask = Set( mask , i-1 );
           for( int j = 0; j < graph[i].size(); j++ ) {
              newmask = Set( newmask , graph[i][j]-1 );
           }
           ret = max( ret , solve( newmask )+ara[i] );
        }
    }
    return dp[mask] = ret;
}
int main( int argc, char const *argv[] ) {
    for( int i = 1; i <= 8; i++ ) scanf("%d",&ara[i]);
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    memset( dp , -1 , sizeof(dp) );
    printf("%d\n",solve( 0 ) );
    return 0;
}






