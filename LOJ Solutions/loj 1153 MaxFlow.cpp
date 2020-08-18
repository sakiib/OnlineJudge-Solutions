#include <bits/stdc++.h>
using namespace std;

struct MAXFLOW_DINITZ {
        typedef long long LL;
        static const int MAXN = 105;
        static const int INF = 2e9 + 5;

        int nodes , src , snk;
        int dist[ MAXN ] , start[ MAXN ];

        struct Edge {
                int nxt , flow , cap , rev;
        };
        vector <Edge> graph[ MAXN ];

        void initialize( int n ) {
                nodes = n;
                for( int i = 0; i <= nodes; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v , int w ) {
                Edge p = { v , 0 , w , (int) graph[v].size() };
                Edge q = { u , 0 , w , (int) graph[u].size() };
                graph[ u ].push_back( p ); graph[ v ].push_back( q );
        }
        bool BFS( ) {
                memset( dist , -1 , sizeof(dist) );
                queue <int> Q; Q.push( src ); dist[ src ] = 0;
                while( !Q.empty() ) {
                        int u = Q.front(); Q.pop();
                        for( int i = 0; i < graph[u].size(); i++ ) {
                                Edge& e = graph[u][i];
                                int v = e.nxt;
                                if( dist[v] == -1 && e.flow < e.cap ) {
                                        dist[v] = dist[u] + 1;
                                        Q.push( v );
                                }
                        }
                }
                return ( dist[snk] != -1 );
        }
        int DFS( int u , int f ) {
                if( u == snk ) return f;
                for( int& i = start[u]; i < graph[u].size(); i++ ) {
                        Edge& e = graph[u][i];
                        if( e.flow >= e.cap ) continue;
                        int v = e.nxt;
                        if( dist[v] == ( dist[u] + 1 ) ) {
                                int _f = DFS( v , min( f , e.cap - e.flow ) );
                                if( _f > 0 ) {
                                        e.flow += _f;
                                        graph[v][e.rev].cap = _f;
                                        return _f;
                                }
                        }
                }
                return 0;
        }
        int MaxFlow( int _src , int _snk ) {
                src = _src , snk = _snk;
                int res = 0;
                while( BFS( ) ) {
                        memset( start , 0 , sizeof(start) );
                        while( int f = DFS( src , INF ) ) {
                                res += f;
                        }
                }
                return res;
        }
} MF;

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , s , t , m;
                scanf("%d %d %d %d",&n,&s,&t,&m);

                MF.initialize( n );

                for( int i = 1; i <= m; i++ ) {
                        int u , v , w;
                        scanf("%d %d %d",&u,&v,&w);
                        MF.AddEdge( u , v , w );
                }
                int mx_flow = MF.MaxFlow( s , t );
                printf("Case %d: %d\n",tc,mx_flow);
        }
        return 0;
}







