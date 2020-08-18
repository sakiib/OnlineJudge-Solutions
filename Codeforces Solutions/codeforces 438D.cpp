#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , q;
LL a[ N ];
LL tree[ 4*N ] , lazy[ 4*N ] , mx[ 4*N ];

void pushup( int node ) {
        int l = node << 1 , r = l + 1;
        tree[node] = tree[l] + tree[r];
        mx[node] = max( mx[l] , mx[r] );
}
void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = mx[node] = a[b];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        pushup( node );
}
void update1( int node , int b , int e , int i , int j , int mod ) {
        if( i > e || j < b || b > e || mx[node] < mod ) return;
        if( b == e ) {
                mx[node] = mx[node]%mod;
                tree[node] = mx[node];
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update1( l , b , m , i , j , mod );
        update1( r , m + 1 , e , i , j , mod );
        pushup( node );
}
void update2( int node , int b , int e , int pos , int v ) {
        if( pos > e || pos < b || b > e ) return;
        if( pos == b && b == e ) {
                mx[node]= tree[node] = v;
                return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update2( l , b , m , pos , v );
        update2( r , m + 1 , e , pos , v );
        pushup( node );
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0;
        if( i <= b && j >= e ) return tree[node];
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        return query( l , b , m , i , j ) + query( r , m + 1 , e , i , j );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        build( 1 , 1 , n );
        while( q-- ) {
                int type;
                cin >> type;
                if( type == 1 ) {
                        int l , r;
                        cin >> l >> r;
                        cout << query( 1 , 1 , n , l , r ) << endl;
                }
                if( type == 2 ) {
                        int l , r , m;
                        cin >> l >> r >> m;
                        update1( 1 , 1 , n , l , r , m );
                }
                if( type == 3 ) {
                        int pos , val;
                        cin >> pos >> val;
                        update2( 1 , 1 , n , pos , val );
                }
        }
        return 0;
}











