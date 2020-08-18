#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 5;

vector <int> graph[ 3*N ] , g[ 3*N ];
vector < pair<int,int> > bridge;
set <int> point;
int Time;
int st[ 3*N ] , low[ 3*N ] , par[ 3*N ] , cost[ 3*N ];
bool visited[ 3*N ];
bool br[ 3*N ];
int f;

void Tarjan( int s , int p = -1 ) {
        st[s] = low[s] = ++Time;
        visited[s] = true;
        for( auto x : graph[s] ) {
                if( x == p ) continue;
                if( visited[x] ) low[s] = min( low[s] , st[x] );
                else {
                        Tarjan( x , s );
                        par[x] = s;
                        low[s] = min( low[s] , low[x] );
                        if( low[x] > st[s] ) bridge.push_back( {s,x} );
                }
        }
}
int Find( int x ) {
        return ( par[x] == x ? x : par[x] = Find( par[x] ) );
}
void build_graph( ) {
        for( auto x : bridge ) {
                int a = x.first , b = x.second;
                int u = Find( a ) , v = Find( b );
                f = u;
                cout << "a : b : " << a << " " << b << endl;
                cout << "u : v : " << u << " " << v << endl;
                g[u].push_back( v );
                g[v].push_back( u );
        }
}
pair <int,int> bfs( int s ) {
        for( int i = 1; i < 3*N; i++ ) cost[i] = inf;
        cost[s] = 0;
        queue <int> Q;
        Q.push( s );
        int prev = s;
        while( !Q.empty() ) {
                int ff = Q.front( ); Q.pop();
                for( auto x : graph[s] ) {
                        if( cost[x] > cost[ff] + 1 ) {
                                cost[x] = cost[ff] + 1;
                                prev = x;
                        }
                }
        }
        return { prev , cost[prev] };
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n , m;
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) par[i] = i;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        Tarjan( 1 );
        for( int i = 1; i <= n; i++ ) cout << "p : " << par[i] << endl;
        //for( auto x : bridge ) cout << x.first << " " << x.second << endl;
        build_graph( );
        pair <int,int> p = bfs( f );
        pair <int,int> q = bfs( p.first );
        cout << q.second << endl;
        return 0;
}






