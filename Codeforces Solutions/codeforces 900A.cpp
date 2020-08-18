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


vector <int> red , black;
int r = 1, b = 2;
int color[ N ];
vector <int> graph[ N ];
bool bipartite = true;

void dfs( int s , int cur ) {
    if( cur == r ) red.push_back( s );
    else black.push_back( s );
    color[ s ] = cur;

    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if(color[ next ] == 0) {
            dfs( next , (cur == r ? b : r));
        }
        else if( color[ next ] == cur ) {
            bipartite = false;
            return;
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    for( int i = 1; i <= n ; i++ ) {
        if( graph[i].size() < 1 ) continue;
        if( !color[i]) {
            dfs( i , r );
        }
    }
    if( !bipartite) {
        cout << -1 <<endl;
        return 0;
    }
    cout << red.size() <<endl;
    for( auto x : red ) cout << x << " ";
    cout << endl;
    cout << black.size() <<endl;
    for( auto x : black ) cout << x << " ";
    cout <<endl;
    return 0;
}


