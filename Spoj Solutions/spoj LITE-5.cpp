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

int Lazy[ 4*N ];

struct segment {
    int one , zero;
} Tree [ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].one = 0;
        Tree[node].zero = 1;
        Lazy[node] = 0;
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node].one = Tree[right].one + Tree[left].one;
    Tree[node].zero = Tree[right].zero + Tree[left].zero;
    Lazy[node] = Lazy[right] + Lazy[left];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        if( Lazy[node]%2 != 0 ) {
            swap( Tree[node].one , Tree[node].zero );
        }
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int  i ,int  j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        swap( Tree[node].one , Tree[node].zero );
        if( b != e ) {
            Lazy[2*node] += 1;
            Lazy[2*node+1] += 1;
        }
        return;
    }
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    Update( left , b , mid , i , j );
    Update( right , mid+1 , e , i , j );
    Tree[node].one = Tree[left].one + Tree[right].one;
    Tree[node].zero = Tree[left].zero + Tree[right].zero;
}
int Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node].one;
    int left = 2*node; int right = 2*node+1; int mid = (b+e)/2;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    int n , q;
    scanf("%d%d",&n,&q);
    Build( 1 , 1 , n );
    while( q-- ) {
        int op , l , r;
        scanf("%d%d%d",&op,&l,&r);
        if( op == 0 ) Update( 1 , 1 , n , l , r );
        else printf("%d\n",Query( 1 , 1 , n , l , r ) );
    }
    return 0;
}

