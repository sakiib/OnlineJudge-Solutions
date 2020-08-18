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

int ara[ N+10 ];

struct DSU {

    int Parent[ N+10 ];
    int Tot[ N+10 ];

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

    dsu.Makeset( N );

    int n;
    scanf("%d",&n);
    int ans = 0;
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
        int l = ara[i]-1;
        int r = ara[i]+1;
        int has = 0;
        ans++;
        if( l >= 1 && l <= N ) {
           if( dsu.Find( ara[i] ) == dsu.Find( l ) ) has++;
           dsu.Union( ara[i] , l );
        }
        if( r >= 1 && r <= N ) {
            if( dsu.Find( ara[i] ) == dsu.Find( r ) ) has++;
            dsu.Union( ara[i] , r );
        }
        ans -= has;
        printf("%d\n",ans);
    }
    printf("Justice\n");
    return 0;
}

