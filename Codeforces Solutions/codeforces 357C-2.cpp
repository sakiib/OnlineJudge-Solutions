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

LL  Tree[ 3*4*N ] , ans[ 3*N ];

/*
void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = 0;
        return;
    }
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = min( Tree[left]  , Tree[right] );
} */
void Update( LL node , LL b , LL e , LL i , LL j , LL winner ) {
    if( i > e || j < b || Tree[node] == inf ) return;
    if( b == e ) {
        if( b == winner ) return;
        ans[b] = winner;
        Tree[node] = inf;
        return;
    }
    LL left = 2*node; LL right = 2*node+1 ; LL mid = (b+e)/2;
    Update( left , b , mid , i , j , winner );
    Update( right , mid+1 , e , i , j , winner );
    Tree[node] = min( Tree[left] , Tree[right] );
}
int main( int argc, char const *argv[] ) {
    LL n , q;
    scanf("%lld%lld",&n,&q);
    // Build( 1 , 1 , n );
    while( q-- ) {
        LL l , r , winner;
        scanf("%lld%lld%lld",&l,&r,&winner);
        Update( 1 , 1 , n , l , r , winner );
    }
    for( int i = 1; i <= n; i++ ) {
        printf("%lld ",ans[i]);
    }
    return 0;
}




