#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int n;

struct doll {
        int w , h;
        doll(){}
        doll( int w , int h ) : w(w) ,h(h) {}
        bool operator <( const doll &q ) const {
                return ( w == q.w ? h < q.h : w < q.w );
        }
} a[ N ];

int tree[ 4*N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = a[b].h;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m ) , build( r , m + 1 , e );
        tree[node] = max( tree[l] , tree[r] );
}
void update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) {
                tree[node] = val;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node] = max( tree[l] , tree[r] );
}
int query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return -1000000;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return max( query( l , b , m , i , j ) , query( r , m + 1 , e , i , j ) );
}
int BS( int l , int r , int val ) {
        int lo = l , hi = r , ret = -1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( a[mid].w > val ) ret = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );
        int t;
        scanf("%d",&t);
        while( t-- ) {
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) {
                        scanf("%d %d",&a[i].w,&a[i].h);
                }
                sort( a + 1 , a + n + 1 );
                build( 1 , 1 , n );
                int ans = 1;
                for( int i = n - 1; i >= 1; i-- ) {
                        int pos = BS( i + 1 , n , a[i].w );
                        if( pos == -1 ) ans++;
                        else {
                               int mx =  query( 1 , 1 , n , pos , n );
                               if( mx <= a[i].h ) ans++;
                               else update( 1 , 1 , n , pos , a[i].h );
                        }
                }
                printf("%d\n",ans);
                memset( tree , 0 , sizeof( tree ) );
        }
        return 0;
}










