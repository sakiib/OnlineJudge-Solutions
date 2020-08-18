#include <bits/stdc++.h>
using namespace std;

struct MAXFLOW_DINITZ {
        typedef long long LL;
        static const int MAXN = 1e3 + 5;
        static const int INF = 2e9 + 5;

        int nodes , src , snk;
        int dist[ MAXN ] , start[ MAXN ];

        struct Edge {
                int nxt , flow , cap , rev;
        };
        vector <Edge> graph[ MAXN ];

        void initialize( int n ) {
                nodes = n;
                for( int i = 0; i < MAXN; i++ ) graph[i].clear();
        }
        void AddEdge( int u , int v , int w ) {
                //cout << "Edges : " << u << " " << v << endl;
                Edge p = { v , 0 , w , (int) graph[v].size() };
                Edge q = { u , 0 , 0 , (int) graph[u].size() };
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
                                if( _f ) {
                                        e.flow += _f;
                                        graph[v][e.rev].flow -= _f;
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
} FLOW;

int main( int argc , char const *argv[] ) {
        map <string,int> M;
        M[ "XXL" ] = 1;
        M[ "XL" ] = 2;
        M[ "L" ] = 3;
        M[ "M" ] = 4;
        M[ "S" ] = 5;
        M[ "XS" ] = 6;
        char s[ 10 ];

        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                int n , m;
                scanf("%d %d",&n,&m);

                int source = 0 , sink = 500;
                FLOW.initialize( m );

                for( int i = 1; i <= m; i++ ) {
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                FLOW.AddEdge( j*m , ( 6 * ( j ) ) + M[s] + m , 1);
                                FLOW.AddEdge( ( 6 * ( j ) ) + M[s] + m , sink , 1 );
                        }
                        scanf("%s",s);
                        for( int j = 1; j <= n; j++ ) {
                                FLOW.AddEdge( j*m , ( 6 * ( j ) ) + M[s] + m , 1 );
                                FLOW.AddEdge( ( 6 * ( j ) ) + M[s] + m , sink , 1 );
                        }
                }
                for( int i = 1; i <= m; i++ ) {
                        FLOW.AddEdge( source , m*i , 1 );
                }
                int flow = FLOW.MaxFlow( source , sink );
                //cout <<"Flow : "<< flow << endl;
                if( flow == m ) printf("Case %d: YES\n",tc);
                else printf("Case %d: NO\n",tc);
        }
        return 0;
}







