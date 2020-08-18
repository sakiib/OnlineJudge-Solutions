#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector <int> graph[ 20005 ];
int cost[ 20005 ];

map<int,ii> M;

void bfs() {
    queue <int,ii> Q;
    Q.push( {0,0,1} );

    while( !Q.empty() ) {
        data f = Q.front();
        Q.pop();
        int a = f.x , b = f.y , c = f.now;
        if( M[{a,b,c}] ) continue;
        for( int i = 0; i < graph[c].size(); i++ ) {
            int next = graph[c][i];
            if(cost[next] == -1 || ( cost[next] > cost[c]+1)) {
                cost[next] = cost[c]+1;
                Q.push({b,c,next});
            }
        }
    }
}
int main( int argc , char const *argv[] ) {
    int n , m , k;
    cin >> n >> m >> k;
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    for( int i = 1; i <= k; i++ ) {
        int x , y , z;
        cin >> x >> y >> z;
        M[{x,y,z}] = true;
    }
    memset( cost  , -1 , sizeof( cost ) );
    bfs();
    return 0;
}
