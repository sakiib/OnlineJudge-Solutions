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

LL divi[ 10*N ];
LL ara[ 3*N ];
LL Tree[ 3*4*N ];
int done[ 3*4*N ];

void calc( ) {
    for( int i = 1; i <= 10*N; i++ ) {
        for( int j = i; j <= 10*N; j += i ) {
            divi[j]++;
        }
    }
}
void Build( int node , int b , int e ) {
    if( b > e ) return ;
    if( b == e ) {
        Tree[node] = ara[b];
        ( Tree[node] <= 2 ? done[ node ] = 0 : 1 );
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = Tree[left] + Tree[right];
}
void Update( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e ) return;
    if( done[ node ] == 0 ) return;
    if( b == e ) {
        Tree[node] = divi[ Tree[node] ];
        ( Tree[node] <= 2 ? done[ node ] = 0 : 1 );
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Update( left , b , mid , i , j );
    Update( right , mid+1 , e , i , j );
    Tree[node] = Tree[left] + Tree[right];
}
LL Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b || b > e ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return q1+q2;
}
int main( int argc, char const *argv[] ) {
    calc( );
    int n , q;
    scanf("%d %d",&n,&q);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&ara[i]);
    Build( 1 , 1 , n );
    while( q-- ) {
        int op , x , y;
        scanf("%d %d %d",&op,&x,&y);
        if( op == 1 ) Update( 1 , 1 , n , x , y );
        else printf("%lld\n",Query( 1, 1 , n , x , y ) );
    }
    return 0;
}

