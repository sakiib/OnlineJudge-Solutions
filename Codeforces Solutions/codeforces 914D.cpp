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

LL ara[ 5*N ] , Tree[ 5*5*N ];
LL n;
bool f;

void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b];
        return;
    }
    LL left = 2*node , right = 2*node+1, mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
void Update( LL node , LL b , LL e , LL pos , LL val ) {
    if( pos > e || pos < b ) return;
    if( b == e && b == pos ) {
        Tree[node] = val;
        return;
    }
    LL left = 2*node , right = 2*node+1, mid = (b+e)/2;
    Update( left , b , mid , pos , val );
    Update( right , mid+1 , e , pos , val );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
LL Query( LL node , LL b , LL e , LL i , LL j ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    LL left = 2*node , right = 2*node+1, mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return __gcd( q1 , q2 );
}
void Check( LL node , LL b , LL e , LL i , LL j , LL G ) {
    LL left = 2*node , right = 2*node+1, mid = (b+e)/2;
    LL L = Query( left , b , mid , i , j  );
    LL R = Query( right , mid+1 , e , i , j  );
    if( L%G != 0 && R%G != 0 ) {
        f = true;
        return;
    }
    if( L%G != 0 ) Check( left , b , mid , i , j , G );
    if( R%G != 0 ) Check( right , mid+1 , e , i , j , G );
}
int main( int argc, char const *argv[] ) {
    scanf("%lld",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    Build( 1 , 1 , n );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int op;
        f = false;
        scanf("%d",&op);
        if( op == 2 ) {
            LL pos , val;
            scanf("%lld%lld",&pos,&val);
            Update( 1 , 1 , n , pos , val );
            continue;
        }
        LL l , r , G;
        scanf("%lld%lld%lld",&l,&r,&G);
        LL Q = Query( 1 , 1 , n , l , r );
        if( Q == G ) {
            puts("YES"); continue;
        }
        Check( 1 , 1 , n , l , r , G );
        if( !f ) puts("YES");
        else puts("NO");
    }
    return 0;
}

