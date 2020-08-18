#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

vector<LL> graph[ 100 ];
bool visited[ 100 ];
LL ans = 1;

void dfs( LL s ) {
    visited [ s ] = true;
    for( int i = 0; i < graph[s].size(); i++ ) {
        LL next = graph[s][i];
        if(!visited[next]) {
            ans *= 2;
            dfs( next );
        }
    }
}
int main( int argc, char const *argv[] ) {
    LL n , m;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ) {
       LL u , v;
       cin >> u >> v;
       graph[u].push_back( v );
       graph[v].push_back( u );
    }
    for( int i = 1; i <= n; i++ ) {
        if( !visited[ i ] ) {
            dfs( i );
        }
    }
    cout << ans <<endl;
    return 0;
}
