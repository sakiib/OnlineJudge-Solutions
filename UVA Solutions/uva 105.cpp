#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template < typename Arg1 >
void __f( const char* name , Arg1&& arg1 ) { cerr << name << " : " << arg1 << "\n"; }
template < typename Arg1 , typename... Args >
void __f( const char* names , Arg1&& arg1 , Args&&... args ) {
const char* comma = strchr( names + 1 , ',' );
cerr.write( names , comma - names ) << " : " << arg1 << " , " ; __f( comma + 1 , args... ); }
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;

int mx[ N ];
int tree[ 4*N ] , lazy[ 4*N ] , idx[ 4*N ];

void pushdown( int node , int b , int e ) {
        if( lazy[node] == 0 ) return;
        int l = node << 1 , r = l | 1 , b = ( b + e ) >> 1;
        tree[l] = max( tree[l] , lazy[node] );
        tree[r] = max( tree[r] , lazy[node] );
        lazy[l] = max( lazy[l] , lazy[node] );
        lazy[r] = max( lazy[r] , lazy[node] );
        lazy[node] = 0;
}
void update( int node , int b , int e , int i , int j , int v ) {
        if( i > e || j < b || b > e ) return;
        if( i <= b && j >= e ) {
                tree[node] = max( tree[node] , v );
                lazy[node] = max( lazy[node] , v );
                return;
        }
        pushdown( node , b , e );
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , i , j , v );
        update( r , m + 1 , e , i , j , v );
        tree[node] = max( tree[l] , tree[r] );
}
int query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        pushdown( node , b , e );
        int x = query( l , b , m , i , j );
        int y = query( r , m + 1 , e , i , j );
        if( )
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        //freopen( "in.txt" , "r" , stdin );
        int l , h , r;
        memset( mx , 0 , sizeof( mx ) );
        while( cin >> l >> h >> r ) {
                for( int i = l; i < r; i++ ) mx[i] = max( mx[i] , h );
        }

        return 0;
}












