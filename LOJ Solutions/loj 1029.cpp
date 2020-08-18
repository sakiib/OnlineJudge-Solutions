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

const int sz = N;

struct DSU {

    int Parent[ sz ];
    int Tot[ sz ];

    inline void Makeset( int k ) {
        for( int i = 0; i <= k; i++ ) {
            Parent[ i ] = i;
            Tot[ i ] = 0;
        }
        //for( int i = 1; i <= 20; i++ ) cout << Parent[i] <<" ";
        //cout << endl;
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

struct data {
    int u , v , w;
    bool operator <( const data &q ) const {
        return w < q.w;
    }
};

vector < data > V;

void MST_Kruskal( ) {
    sort( V.begin( ) , V.end( ) );
    dsu.Makeset( 105 );
    int mn = 0;
    for( int i = 0; i < V.size(); i++ ) {
        int x = V[i].u , y = V[i].v , z = V[i].w;
        if( dsu.Find( x ) != dsu.Find( y ) ) {
            dsu.Union( x , y );
            mn += z;
        }
    }
    dsu.Makeset( 105 );
    int mx = 0;
    for( int i = V.size()-1; i >= 0; i-- ) {
        int x = V[i].u , y = V[i].v , z = V[i].w;
        if( dsu.Find( x ) != dsu.Find( y ) ) {
            dsu.Union( x , y );
            mx += z;
        }
    }
    int ans = mn+mx;
    if( ans%2 == 0 ) printf("%d\n",ans/2);
    else printf("%d/2\n",ans);
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n;
        scanf("%d",&n);
        while( 1 ) {
            int a , b , c;
            scanf("%d %d %d",&a,&b,&c);
            if( !a && !b && !c ) break;
            V.push_back( data{ a , b , c } );
        }
        printf("Case %d: ",tc);
        MST_Kruskal( );
        V.clear( );
    }
    return 0;
}

