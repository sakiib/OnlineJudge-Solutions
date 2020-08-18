#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
string s;
int len , q;
LL tree[ 4 * N ];

void build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) {
                tree[node] = s[b]-'0'; return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        build( l , b , m );
        build( r , m + 1 , e );
        tree[node] = tree[l] + tree[r];
}
void update( int node , int b , int e , int pos , int val ) {
        if( b > e || pos > e || pos < b ) return;
        if( b == e && b == pos ) {
                tree[node] = val; return;
        }
        int l = node << 1 , r = l | 1 , m = ( b + e ) >> 1;
        update( l , b , m , pos , val );
        update( r , m + 1 , e , pos , val );
        tree[node] = tree[l] + tree[r];
}
LL query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return 0LL;

}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> len >> q >> s;
        s = " " + s;
        build( 1 , 1 , len );
        cout << tree[1] << endl;

        while( q-- ) {
                int type;
                cin >> type;
                if( type == 1 ) {
                        int pos , val;
                        cin >> pos >> val;
                        update( 1 , 1 , len , pos , val );
                }
                else {
                        int l , r;
                        cin >> l >> r;
                        cout << query( 1 , 1 , len , l , r );
                }
        }
        return 0;
}






