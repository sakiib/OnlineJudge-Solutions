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

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

struct query {
        int l , r , q;
} Q[ N ];

int sum[ N ][ 31 ] , ans[ N ] , tree[ 4*N ];
int n , q;

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = ans[b]; return;
        }
        int l = node << 1 , r = l | 1 , m = (b+e) >> 1;
        build( l , b , m ) , build( r , m+1 , e ) , tree[node] = ( tree[l]&tree[r] );
}
int query( int node , int b , int e , int i , int j ) {
        if( b > e || i > e || j < b ) return ( 1 << 30 )-1;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = (b+e) >> 1;
        return  ( query( l , b , m , i , j )&query( r , m+1 , e , i , j ) );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> q;
        for( int i = 1; i <= q; i++ ) cin >> Q[i].l >> Q[i].r >> Q[i].q;
        for( int i = 1; i <= q; i++ ) {
                for( int j = 0; j <= 30; j++ ) {
                        if( Check( Q[i].q , j ) ) sum[ Q[i].l ][ j ]++ , sum[ Q[i].r+1 ][ j ]--;
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 0; j <= 30; j++ ) {
                        sum[ i ][ j ] += sum[ i-1 ][ j ];
                }
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 0; j <= 30; j++ ) {
                        if( sum[i][j] > 0 ) ans[i] = Set( ans[i] , j );
                }
        }
        build( 1 , 1 , n );
        for( int i = 1; i <= q; i++ ) {
                int cur = query( 1 , 1 , n , Q[i].l , Q[i].r );
                if( cur != Q[i].q ) return cout << "NO" << endl,0;
        }
        cout << "YES" << endl;
        for( int i = 1; i <= n; i++ ) cout << ans[i] << " ";
        return 0;
}
