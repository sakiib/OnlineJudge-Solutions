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
#define all( V )  ( V.begin() , V.end() )

int n , a[ 2*N ];
set <int> tree[ 2*4*N ];
LL ans;

set <int> Merge( set <int> a , set <int> b ) {
        a.insert( b.begin() , b.end() );
        return a;
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node].insert( a[b] );
                return;
        }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        build( left , b , mid );
        build( right , mid+1 , e );
        tree[node] = Merge( tree[left] , tree[right] );
}
int query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) {

        }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        return ( query( left , b , mid , i , j ) + query( right , mid+1 , e , i , j ) );
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
        build( 1 , 1 , n );
        int q;
        scanf("%d",&q);
        while( q-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                printf("ans  = %d\n",query( 1 , 1 , n , l , r ) );
                printf("********\n");
        }
        return 0;
}






