#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ N ] , Tree[ 4*N ] , Lazy[ 4*N ];

void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b];
        Lazy[node] = 0;
        return;
    }
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
    Lazy[node] = Lazy[left] + Lazy[right];
}
void Propagate( ) {

}
void Update( LL node , LL b , LL e , LL i , LL j ) {

}
LL Query( LL node , LL b , LL e , LL i , LL j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    Build( 1 , 1 , n );
    LL q;
    cin >> q;
    while( q-- ) {
        LL op;
        cin >> op;
        if( op == 1 ) {
            LL  l , r;
            cin >> l >> r;
            LL ans = Query( 1 , 1 , n , l , r );
        }
        else {
            LL l , r , val;
            cin >> l >> r >> val;
            Update( 1 , 1 , n , l, r , val );
        }
    }
    return 0;
}

