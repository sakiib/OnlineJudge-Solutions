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

int ara[ 5*N ] , Tree[ 4*5*N ];
int n , res = 0;

inline void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b];
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
inline void Update( int node , int b , int e , int pos , int val ) {
    if( pos > e || pos < b ) return;
    if( b == e && b == pos ) {
        Tree[node] = val;
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Update( left , b , mid , pos , val );
    Update( right , mid+1 , e , pos , val );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
inline void Query( int node , int b , int e , int i , int j , int G ) {
    if( i > e || j < b || res > 1 ) return;
    if( b == e ) {
        if( Tree[node]%G != 0 ) res++;
        return;
    }
    if( i <= b && j >= e && Tree[node]%G == 0 ) return;
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Query( left , b , mid , i , j , G );
    Query( right , mid+1 , e , i , j , G );
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    Build( 1 , 1 , n );
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int op; res = 0;
        scanf("%d",&op);
        if( op == 2 ) {
            int pos , val;
            scanf("%d%d",&pos,&val);
            Update( 1 , 1 , n , pos , val );
        }
        else {
            int l , r , G;
            scanf("%d%d%d",&l,&r,&G);
            Query( 1 , 1 , n , l , r , G );
            if( res <= 1 ) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
