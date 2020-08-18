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

LL ara[ 2*N ] , val[ 2*N ] , Tree[ 4*2*N ];

void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = 0;
        return;
    }
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( LL node , LL b , LL e , LL i , LL j ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node];
     LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
     LL q1 = Query( left , b , mid , i , j );
     LL q2 = Query( right , mid+1 , e , i , j );
     return ( q1+q2 );
}
void Update( LL node , LL b , LL e , LL pos , LL val ) {
    if( pos > e || pos < b ) return;
    if( b == e && b == pos ) {
        Tree[node] += val;
        return;
    }
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    Update( left , b , mid , pos , val );
    Update( right , mid+1 , e , pos , val );
    Tree[node] = Tree[left] + Tree[right];
}
int main( int argc, char const *argv[] ) {
    LL n , k , q;
    cin >> n >> k >> q;
    for( int i = 1; i <= n; i++ ) {
        LL  l ,r;
        cin >> l >> r;
        ara[r+1] -- , ara[l]++;
    }
    for( int i = 1; i <= 2*N; i++ ) {
        ara[i] += ara[i-1];
        if( ara[i] >= k ) Update( 1 , 1 , 2*N , i , 1 );
    }
    //Build( 1 , 1 , 2*N );
    while( q-- ) {
        LL l , r;
        cin >> l >> r;
        cout << Query( 1 , 1 , 2*N , l , r ) << endl;
    }
    return 0;
}

