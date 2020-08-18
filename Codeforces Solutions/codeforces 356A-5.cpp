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

int n , m;
int ans[ 3*N ] , Tree[ 3*4*N ];



inline int In() {
	int x = 0,f = 1; char ch = getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) if(ch=='-') f=-1;
	for( ; ch>='0' && ch<='9'; x=(x<<3)+(x<<1)+ch-'0', ch=getchar());
	return ( x*f );
}
inline void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node] = b;
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    Tree[node] = min( Tree[node] , Tree[right] );
}
inline void Update( int node , int b , int e , int i , int j , int win ) {
    if( i > e || j < b ) return;
    if( i <= b && j >= e && Tree[node] == inf ) return;
    if( b == e ) {
        if( Tree[node] == inf || b == win ) return;
        ans[b] = win;
        Tree[node] = inf;
        return;
    }
    int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
    Update( left , b , mid , i , j , win );
    Update( right , mid+1 , e , i , j , win );
    Tree[node] = min( Tree[left] , Tree[right] );
}
int main( int argc, char const *argv[] ) {
    n = In() , m = In();
    Build( 1 , 1 , n );
    for( int i = 1; i <= m; i++ ) {
        int x , y , w;
        x = In() , y = In() , w = In();
        Update( 1 , 1 , n , x , y , w );
    }
    for( int i = 1; i <= n; i++ ) {
        printf("%d ",ans[i] );
    }
    return 0;
}

