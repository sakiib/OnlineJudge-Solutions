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

LL ara[ 2*N ] , Tree[ 8*N ] , Lazy[ 8*N ] , add[ 2*N ];

void Propagate( LL node , LL b , LL e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] += Lazy[node];
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( LL node , LL b , LL e , LL i , LL j , LL val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] += val;
        if( b != e ) {
            Lazy[2*node] += val;
            Lazy[2*node+1] += val;
        }
        return;
    }
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( LL node , LL b , LL e , LL pos ) {
    Propagate( node , b , e );
    if( pos > e || pos < b ) return 0;
    if( b == e && b == pos ) return Tree[node];
    LL left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , pos );
    LL q2 = Query( right , mid+1 , e , pos );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    LL n , q;
    scanf("%lld%lld",&n,&q);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    while( q-- ) {
        LL l , r;
        scanf("%lld%lld",&l,&r);
        Update( 1 , 1 , n , l , r , +1 );
    }
    for( int i = 1; i <= n; i++ ) {
        add[i] = Query( 1 , 1 , n , i );
    }
    sort( ara+1 ,ara+n+1 );
    sort( add+1 , add+n+1 );
    LL sum = 0;
    for( int i = 1; i <= n; i++ ) {
        sum += ( add[i] * ara[i] );
    }
    printf("%lld\n",sum);
    return 0;
}

