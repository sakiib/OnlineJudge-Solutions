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

int ara [ N ] , Tree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b];
        return;
    }
    int left = 2*node ; int right = 2*node+1; int mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = min( Tree[left] , Tree[right] );
}
int Query( int node , int b , int e ,int i , int j ) {
    if( i > e || j < b ) return inf;
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node ; int right = 2*node+1; int mid = (b+e)/2;
    int q1 = Query( left , b , mid , i , j );
    int q2 = Query( right , mid+1 , e , i , j );
    return ( min( q1 , q2 ) );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t ; tc++ ) {
        int n , q;
        scanf("%d%d",&n,&q);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        Build( 1 , 1 , n );
        printf("Case %d:\n",tc);
        while( q-- ) {
            int l , r;
            scanf("%d%d",&l,&r);
            printf("%d\n",Query( 1 , 1 , n , l , r ) );
        }
        memset( Tree , 0 , sizeof( Tree ) );
    }
    return 0;
}

