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

LL a[ N ] , sum[ N ] , ans[ N ];
int n , q[ N ] , parent[ N ];
bool added[ N ];

void makeset( ) {
        for( int i = 1; i <= n; i++ ) parent[i] = i , sum[i] = a[i];
}
int Find( int x ) {
        return ( parent[x] == x ? x : parent[x] = Find( parent[x] ) );
}
void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) parent[u] = v , sum[v] += sum[u];
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&a[i]);
        for( int i = 1; i <= n; i++ ) scanf("%d",&q[i]);
        makeset( );
        LL mx_sum = -INF;
        for( int i = n; i >= 1; i-- ) {
                ans[i] = mx_sum;
                added[ q[i] ] = true;
                if( added[ q[i]+1 ] ) Union( q[i] , q[i]+1 );
                if( added[ q[i]-1 ] ) Union( q[i] , q[i]-1 );
                mx_sum = max( mx_sum , sum[ Find(q[i]) ] );
        }
        for( int i = 1; i <= n; i++ ) printf("%lld\n",ans[i]);
        return 0;
}






