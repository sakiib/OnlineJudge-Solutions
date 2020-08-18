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

LL ara[ 5*N ] , Tree[ 4*5*N ];
LL n , res = 0;

int In(){
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';x=(x<<3)+(x<<1)+ch-'0',ch=getchar());
	return x*f;
}
inline void Build( LL node , LL b , LL e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = ara[b];
        return;
    }
    LL left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
inline void Update( LL node , LL b , LL e , LL pos , LL val ) {
    if( pos > e || pos < b ) return;
    if( b == e && b == pos ) {
        Tree[node] = val;
        return;
    }
    LL left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Update( left , b , mid , pos , val );
    Update( right , mid+1 , e , pos , val );
    Tree[node] = __gcd( Tree[left] , Tree[right] );
}
inline void Query( LL node , LL b , LL e , LL i , LL j , LL G ) {
    if( i > e || j < b || res > 1 ) return;
    if( b == e ) {
        if( Tree[node]%G != 0 ) res++;
        return;
    }
    if( i <= b && j >= e && Tree[node]%G == 0 ) return;
    LL left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Query( left , b , mid , i , j , G );
    Query( right , mid+1 , e , i , j , G );
}
int main( int argc, char const *argv[] ) {
    n = In();
    for( int i = 1; i <= n; i++ ) {
        ara[i] = In();
    }
    Build( 1 , 1 , n );
    int q;
    q = In();
    while( q-- ) {
        int op; res = 0;
        op = In();
        if( op == 2 ) {
            LL pos , val;
            pos = In() , val = In();
            Update( 1 , 1 , n , pos , val );
        }
        else {
            LL l , r , G;
            l = In() , r = In() , G = In();
            Query( 1 , 1 , n , l , r , G );
            if( res <= 1 ) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}


