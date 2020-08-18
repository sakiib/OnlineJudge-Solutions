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

typedef pair<LL,LL> pll;
LL val[ N ];
vector <pll> graph[ N ];
LL child[ N ];
LL ans = 0;

void dfs1( LL s , LL par ) {
    child[ s ] = 1;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        pll p = graph[ s ][ i ];
        LL node = p.first;
        if( node == par ) continue;
        dfs1( node , s );
        child[ s ] += child[ node ];
    }
}
void dfs2( LL s , LL par , LL cost , LL mincost ) {
    mincost = min( mincost , cost );
    if( cost-mincost > val[s] ) {
        ans += child[s];
        return;
    }
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        pll p = graph[ s ][ i ];
        LL node = p.first;
        LL c = p.second;
        if( node == par ) continue;
        dfs2( node , s , cost+c , mincost );
    }
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> val[i];
    }
    for( LL i = 2; i <= n; i++ ) {
        LL u , c;
        cin >> u >> c;
        graph[ i ].push_back( {u,c} );
        graph[ u ].push_back( {i,c} );
    }
    dfs1( 1 , 0 );
    dfs2( 1 , 0 , 0 , INF );
    cout << ans << endl;
    return 0;
}

