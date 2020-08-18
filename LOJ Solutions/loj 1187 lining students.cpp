#include <bits/stdc++.h>
using namespace std;

template <typename T> class segment_tree {
    public:
        static const int N = 1e5 + 5;
        T tree[ 4*N ];
        void init( ) {
                memset( tree , 0 , sizeof( tree ) );
        }
        void build( int node , int b , int e ) {
                if( b > e ) return;
                if( b == e ) {
                        tree[node] = 1;
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                build( l , b , m );
                build( r , m + 1 , e );
                tree[node] = tree[l] + tree[r];
        }
        void update( int node , int b , int e , int pos ) {
                if( pos > e || pos > e || pos < b ) return;
                if( b == e && b == pos ) {
                        tree[node] = 0;
                        return;
                }
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                update( l , b , m , pos );
                update( r , m + 1 , e , pos );
                tree[node] = tree[l] + tree[r];
        }
        int query( int node , int b , int e , int k ) {
                if( b == e ) return b;
                int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
                if( tree[l] < k ) return query( r , m + 1 , e , k - tree[l] );
                else return query( l , b , m , k );
        }
    private:
        static const int inf = 1e9 + 7;
};

segment_tree <int> seg;

const int N = 1e5 + 5;
int a[ N ];
int ans[ N ];

int main( ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                scanf("%d",&n);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                seg.init( );
                seg.build( 1 , 1 , n );
                for( int i = n; i > 1; i-- ) {
                        int tot = seg.tree[1];
                        ans[i] = n - a[i];
                        seg.update( 1 , 1 , n , ans[i] );
                }
                ans[1] = seg.query( 1 , 1 , n , 1 );
                for( int i = 1; i <= n; i++ ) printf("%d ",ans[i]);
        }
        return 0;
}






