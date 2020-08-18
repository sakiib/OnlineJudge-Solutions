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

LL ara[ N ];
LL Tree[ 4*N ] , Lazy[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) { Tree[node] = ara[b]; return; }
    int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = min( Tree[left] , Tree[right] );
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] = ( Tree[node]&Lazy[node] );
        if( b != e ) {
            Lazy[2*node] = Lazy[node];
            Lazy[2*node+1] = Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int i , int j , LL val ) {
    if( i > e || j < b || b > e ) return;
    Propagate( node , b , e );
    if( i <= b && j >= e ) {
        Tree[node] = (Tree[node]&val);
        if( b != e ) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = min( Tree[left] , Tree[right] );
}
LL Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e ) return INF;
    Propagate( node , b , e );
    if( i <= b && j >= e ) return Tree[node];
    int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
    LL Q1 = Query( left , b , mid , i , j );
    LL Q2 = Query( right , mid+1 , e , i , j );
    return min( Q1 , Q2 );
}
int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&ara[i]);
    Build( 1 , 1 , n );
    while( q-- ) {
        int op;
        scanf("%d",&op);
        if( op == 0 ) {
            int l , r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",Query( 1 , 1 , n , l , r ) );
        }
        else {
            int l , r;
            LL val;
            scanf("%d %d %lld",&l,&r,&val);
            Update( 1 , 1 , n , l , r , val );
        }
    }
    return 0;
}

