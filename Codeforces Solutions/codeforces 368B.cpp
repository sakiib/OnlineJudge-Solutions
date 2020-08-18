#include <bits/stdc++.h>
using namespace std;

typedef long  long LL;
const int N = 100005;
const LL inf = 1000000000000;
typedef pair<LL,LL> ii;

vector < ii > graph[ N ];
LL cost[ N ];
LL factory[ N ];
map <LL,bool> has;

int main( int argc , char const *argv[] ) {
    LL n , m , k;
    cin >> n >> m >> k;
    for( int i = 1; i <= m; i++ ) {
        LL u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back( {v,w} );
        graph[v].push_back( {u,w} );
    }
    for( int i = 1; i <= k; i++ ) {
        cin >> factory[i];
        has[ factory[i] ] = true;
    }
    LL ans = inf;
    for( int i = 1; i <= k; i++ ) {
        LL f = factory[i];
        for( int j = 0; j < graph[f].size(); j++ ) {
            ii node = graph[f][j];
            if( has[node.first] ) continue;
            ans = min( ans , node.second);
        }
    }
    cout << ( ans == inf ? -1 : ans ) <<endl;
    return 0;
}
