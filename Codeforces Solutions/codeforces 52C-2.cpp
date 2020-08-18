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

LL ara[ 2*N ] , Tree[ 2*4*N ] = {0} , Lazy[ 2*4*N ] = {0};

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
        Lazy[2*node+1] +=val;
        }
        return;
    }
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = min( Tree[left] , Tree[right] );
}
LL Query( LL node , LL b , LL e , LL i , LL j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return INF;
    if( i <= b && j >= e ) return Tree[node];
    LL left = 2*node; LL right = 2*node+1; LL mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return min( q1  , q2 );
}
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
    Tree[node] = min( Tree[left] , Tree[right] );
    Lazy[node] = Lazy[left] + Lazy[right];
}
int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    Build( 1 , 1 , n );
    LL q;
    scanf("%lld",&q);
    while( q-- ) {
        LL l , r , val;
        char ch;
        scanf("%lld%lld%c",&l,&r,&ch);
        l++ , r++;
        if( ch != '\n' ) {
            scanf("%lld",&val);
            if( l <= r ) Update( 1 , 1 , n , l , r , val );
            else {
                Update( 1 , 1 , n , l , n , val );
                Update( 1 , 1 , n , 1 , r , val );
            }
        }
        else {
            if( l <= r ) {
                LL ans = Query( 1 , 1 , n , l , r );
                printf("%lld\n",ans);
            }
            else {
                LL ans1 = Query( 1 , 1 , n , l , n );
                LL ans2 = Query( 1 , 1 , n , 1 , r );
                printf("%lld\n",min( ans1 , ans2 ) );
            }
        }
    }
    return 0;
}



