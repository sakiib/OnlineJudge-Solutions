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

LL cost[ N ];
vector <int> graph[ N ];
bool visited[ N ];
LL mn;

LL dfs( int s ) {
    visited[ s ] = true;
    mn = min( mn , cost[s] );
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            dfs( next );
        }
    }
    return mn;
}
int main( int argc, char const *argv[] ) {
    int n , e;
    cin >> n >> e;
    for( int i = 1; i <= n; i++ ) {
        cin >> cost[i];
    }
    for( int i = 1; i <= e; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    LL ans = 0;
    for( int i = 1; i <= n; i++ ) {
        mn = INF;
        if( !visited[i] ) {
            ans += dfs( i );
        }
    }
    cout << ans << endl;
    return 0;
}

