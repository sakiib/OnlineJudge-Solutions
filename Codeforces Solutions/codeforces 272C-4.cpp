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

void Build( int node , int b , int e ) {
    if( b > e ) return ;
    if( b == e ) {
        Tree[node] = ara[b];
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = max( Tree[right] , Tree[left] );
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        Tree[node] = ( Lazy[node] );
        if( b != e ) {
            Lazy[2*node] = Lazy[node];
            Lazy[2*node+1] = Lazy[node];
        }
        Lazy[node] = 0;
    }
}
LL Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return -INF;
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return max( q1 , q2 );
}
void Update( int node , int b , int e , int i , int j , LL val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node] = val;
        if( b != e ) {
            Lazy[2*node] = val;
            Lazy[2*node+1] = val;
        }
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e , i , j , val );
    Tree[node] = max( Tree[left] , Tree[right] );
}
int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    Build( 1 , 1 , n );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        LL w , h;
        scanf("%lld%lld",&w,&h);
        LL hit = Query( 1 , 1 , n , 1 , w );
        printf("%lld\n",hit);
        Update( 1 , 1 , n , 1 , w , hit+h );
    }
    return 0;
}

