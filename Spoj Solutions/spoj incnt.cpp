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

int ara[ 2*N ] , Tree[ 100*N*4 ];

void Update( int node , int b , int e , int pos , int val ) {
    if( pos > e || pos < b ) return;
    if( b == e && b == pos ) {
        Tree[node] += val;
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b ,mid , pos ,val );
    Update( right , mid+1 , e , pos , val );
    Tree[node] = Tree[left]+ Tree[right];
}
LL Query( int node , int b , int e , int i , int j ) {
    if( i > e || j < b ) return 0;
    if( i <= b && j >= e ) return Tree[node];
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    LL q1 = Query( left , b , mid , i , j );
    LL q2 = Query( right , mid+1 , e , i , j );
    return ( q1+q2 );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        LL ans = 0;
        for( int i = n; i >= 1; i-- ) {
            ans += Query( 1 , 1 , 100*N , 1 , ara[i]-1 );
            Update( 1 , 1 , 100*N , ara[i] , +1 );
        }
        printf("%lld\n",ans);
        memset( Tree , 0 , sizeof(Tree) );
    }
    return 0;
}
