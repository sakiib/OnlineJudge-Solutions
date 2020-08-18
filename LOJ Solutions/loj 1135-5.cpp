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
    int one , two , zero;
    void Exchange() {
        int temp = zero;
        zero = two;
        two = one;
        one = temp;
    }
} Tree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].zero = 1;
        Tree[node].one = 0;
        Tree[node].two = 0;
        Lazy[node] = 0;
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node].zero = Tree[left].zero + Tree[right].zero;
    Tree[node].one = Tree[left].one + Tree[right].one;
    Tree[node].two = Tree[left].two + Tree[right].two;
    Lazy[node] = Lazy[left] + Lazy[right];
}
void Propagate( int node , int b , int e ) {
    if( Lazy[node] != 0 ) {
        int k = Lazy[node]%3;
        if( k == 1 ) {
            Tree[node].Exchange();
        }
        if( k == 2 ) {
            Tree[node].Exchange();
            Tree[node].Exchange();
        }
        if( b != e ) {
            Lazy[2*node] += Lazy[node];
            Lazy[2*node+1] += Lazy[node];
        }
        Lazy[node] = 0;
    }
}
void Update( int node , int b , int e , int i , int j , int val ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return;
    if( i <= b && j >= e ) {
        Tree[node].Exchange();
        if( b != e ) {
            Lazy[2*node] += val;
            Lazy[2*node+1] += val;
        }
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , i , j , val );
    Update( right , mid+1 , e, i , j , val );
    Tree[node].zero = Tree[left].zero + Tree[right].zero;
    Tree[node].one = Tree[left].one + Tree[right].one;
    Tree[node].two = Tree[left].two + Tree[right].two;
}
int Query( int node , int b , int e , int i , int j ) {
    Propagate( node , b , e );
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node].zero;
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , q;
        scanf("%d%d",&n,&q);
        Build( 1, 1 , n );
        printf("Case %d:\n",tc);
        while( q-- ) {
            int op , l , r;
            scanf("%d%d%d",&op,&l,&r);
            l++ , r++;
            if( op == 0 ) Update( 1 , 1 , n , l , r , 1 );
            else printf("%d\n",Query( 1 , 1 , n , l , r ) );
        }
        memset( Tree , 0 , sizeof( Tree ) );
        memset( Lazy , 0 , sizeof( Lazy ) );
    }
    return 0;
}

