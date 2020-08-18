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


const int sz =  N;

struct SegmentTree {
    LL Tree[ 4*sz ] , Lazy[ 4*sz ];
    LL ara[ sz ];

    inline void Init( ) {
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , 0 , sizeof( Lazy ) );
    }
    inline void LazyPropagate( int node , int b , int e ) {
        if( Lazy[ node ] != 0 ) {
            Tree[ node ] = Lazy[ node ];
            if( b != e ) {
                Lazy[ 2*node ] = Lazy[ node ];
                Lazy[ 2*node+1 ] = Lazy[ node ];
            }
            Lazy[ node ] = 0;
        }
    }
    inline void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) { Tree[node] = ara[b]; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Build( left , b , mid );
        Build( right , mid+1 , e );
        Tree[ node ] = max( Tree[ left ] , Tree[ right ] );
    }
    inline void Update( int node , int b , int e , int i , int j , LL val ) {
        LazyPropagate( node , b , e );
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
            Tree[ node ] = val;
            if( b != e ) {
                Lazy[ 2*node ] = val;
                Lazy[ 2*node+1 ] = val;
            } return;
        }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Update( left , b , mid , i , j , val );
        Update( right , mid+1 , e , i , j , val );
        Tree[ node ] = max( Tree[ left ] , Tree[ right ] );
    }
    inline LL Query( int node , int b , int e , int i , int j ) {
        LazyPropagate( node , b , e );
        if( i > e || j < b || b > e ) return -inf;
        if( i <= b && j >= e ) return Tree[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        LL Q1 = Query( left , b , mid , i , j );
        LL Q2 = Query( right , mid+1 , e , i , j );
        return max( Q1 , Q2 );
    }

} segtree;

int main( int argc , char const *argv[] ) {

    segtree.Init( );
    LL n;
    scanf("%lld",&n);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&segtree.ara[i]);
    segtree.Build( 1 , 1 , n );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        LL w , h;
        scanf("%lld%lld",&w,&h);
        LL hit = segtree.Query( 1 , 1 , n , 1 , w );
        printf("%lld\n",hit);
        segtree.Update( 1 , 1 , n , 1 , w , hit+h );
    }
    return 0;
}



