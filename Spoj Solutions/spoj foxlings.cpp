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

int n , k;
map < int , int > M;


struct DSU {

    int Parent[ 2*N+10 ];
    int Tot[ 2*N+10 ];

    inline void Makeset( int k ) {
        for( int i = 0; i <= k; i++ ) {
            Parent[ i ] = i; Tot[ i ] = 0;
        }
    }
    inline int Find( int x ) {
        if( Parent[ x ] == x ) return x;
        return Parent[ x ] = Find( Parent[ x ] );
    }
    inline void Union( int x , int y ) {
        int u = Find( x ) , v = Find( y );
        if( u != v ) Parent[ u ] = v , Tot[ v ] += Tot[ u ];
    }
};

DSU dsu;

int main( int argc, char const *argv[] ) {

    scanf("%d %d",&n,&k);
    int id = 0;

    dsu.Makeset( 2*N );

    for( int i = 1; i <= k; i++ ) {
        int a , b;
        scanf("%d %d",&a,&b);
        if( M[a] == 0 ) M[a] = ++id;
        if( M[b] == 0 ) M[b] = ++id;
        if( dsu.Find( M[a] ) != dsu.Find( M[b] ) ) dsu.Union( M[a] , M[b] );
    }
    int ans = 0;
    for( int i = 1; i <= id; i++ ) if( dsu.Parent[i] == i ) ans++;
    ans += ( n-id );
    printf("%d\n",ans);
    return 0;
}

