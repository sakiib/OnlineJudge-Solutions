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

LL ara[ 3*N ] , NOD[ 10*N ];

struct segment {
    LL mx , sum;
};

segment Tree[ 3*4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].mx = Tree[node].sum = ara[b];
        return;
    }
    int l = node << 1 , r = l | 1 , mid = ( b+e ) >> 1;
    Build( l , b , mid );
    Build( r , mid+1 , e );
    Tree[node].mx = max( Tree[l].mx , Tree[r].mx );
    Tree[node].sum = Tree[l].sum + Tree[r].sum;
}
void Update( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e || Tree[node].mx <= 2 ) return;
    if( b == e ) {
        Tree[node].sum = NOD[ Tree[node].sum ];
        Tree[node].mx = Tree[node].sum;
        return;
    }
    int l = node << 1 , r = l | 1 , mid = ( b+e ) >> 1;
    Update( l , b , mid , i , j );
    Update( r , mid+1 , e , i , j );
    Tree[node].mx = max( Tree[l].mx , Tree[r].mx );
    Tree[node].sum = Tree[l].sum + Tree[r].sum;
}
LL Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e ) return 0;
    if( i <= b && j >= e ) return Tree[node].sum;
    int l = node << 1 , r = l | 1 , mid = ( b+e ) >> 1;
    LL q1 = Query( l , b , mid , i , j );
    LL q2 = Query( r , mid+1 , e , i , j );
    return ( q1+q2 );
}
void calc( ) {
    for( int i = 1; i <= 10*N; i++ ) {
        for( int j = i; j <= 10*N; j += i ) {
            NOD[j]++;
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , q;
    calc( );
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&ara[i]);
    Build( 1 , 1 , n );
    while( q-- ) {
        int op , x , y;
        scanf("%d %d %d",&op,&x,&y);
        if( op == 1 ) Update( 1 , 1 , n , x , y );
        else printf("%lld\n", Query( 1 , 1 , n , x , y ) );
    }
    return 0;
}

