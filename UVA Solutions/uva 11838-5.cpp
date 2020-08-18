#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
vector <int> graph[ N ] , rev_graph[ N ];
bool vis[ N ];
stack <int> St;
vector <int> component[ N ];
int compo_size;
int n , m;

void topo_sort( int s ) {
        vis[ s ] = true;
        for( auto x : graph[s] ) if( !vis[x] ) topo_sort( x );
        St.push( s );
}
void kosaraju( int s ) {
        vis[ s ] = true;
        component[ compo_size ].push_back( s );
        for( auto x : rev_graph[s] ) if( !vis[x] ) kosaraju( x );
}
void SCC( ) {
        memset( vis , false , sizeof(vis) );
        for( int i = 1; i <= n; i++ ) {
                if( !vis[i] ) topo_sort( i );
        }
        memset( vis , false , sizeof(vis) );
        while( !St.empty() ) {
                int tp = St.top();
                St.pop();
                if( !vis[tp] ) compo_size++ , kosaraju( tp );
        }
}
int main( int argc , char const *argv[] ) {
        while( scanf("%d %d",&n,&m) ) {
                if( n == 0 && m == 0 ) break;
                for( int i = 1; i <= m; i++ ) {
                        int u , v , c;
                        scanf("%d %d %d",&u,&v,&c);
                        if( c == 1 ) {
                                graph[u].push_back( v );
                                rev_graph[v].push_back( u );
                        }
                        else {
                                graph[u].push_back( v );
                                graph[v].push_back( u );
                                rev_graph[u].push_back( v );
                                rev_graph[v].push_back( u );
                        }
                }
                SCC( );

                if( compo_size == 1 ) printf("1\n");
                else printf("0\n");
                for( int i = 1; i < N; i++ ){
                        graph[i].clear();
                        rev_graph[i].clear();
                        component[i].clear();
                        compo_size = 0;
                }
        }
        return 0;
}






