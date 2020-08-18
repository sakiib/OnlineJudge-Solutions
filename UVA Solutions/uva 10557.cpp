#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
typedef long long LL;
const int INF = 1e9;

int n , m;

struct Edge {
        int u , v , w;
        Edge(){}
        Edge( int u , int v , int w ): u(u) , v(v) , w(w){}
};

int cost[ N ];
vector <Edge> V;
bool Neg[ N ];
vector <int> graph[ N ];

bool bfs( int s , int p , int e ) {
        queue <int> Q;
        bool visited[ 105 ];
        memset( visited , false , sizeof(visited) );
        Q.push( s );
        visited[s] = true;
        while( !Q.empty() ) {
                int f = Q.front(); Q.pop();
                if( visited[e] ) return true;
                visited[f] = true;
                for( auto x : graph[f] ) {
                        if( !visited[x] ) Q.push( x );
                }
        }
        return visited[e];
}
bool BellmanFord( int s ) {
        for( int i = 1; i <= n; i++ ) cost[ i ] = INF;
        cost[ 1 ] = -100;
        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < V.size(); j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                        }
                }
        }

        //for( int i = 0; i < V.size(); i++ ) {
        //        if( cost[ V[i].u ] + V[i].w < cost[ V[i].v ]  ) return -1;
        //}

        for( int i = 1; i < n; i++ ) {
                for( int j = 0; j < V.size(); j++ ) {
                        if( cost[ V[j].u ] + V[j].w < cost[ V[j].v ] ) {
                               cost[ V[j].v ] = cost[ V[j].u ] + V[j].w;
                               //cout << "in " << V[j].v << endl;
                               if( bfs( 1 , 0 , V[j].v ) && bfs( V[j].v , 0 , 5 ) ) return true;

                               //Neg[ V[j].v ] = true;
                        }
                }
        }
        return cost[5] < 0;
}

int main( int argc , char const *argv[] ) {
        while( scanf("%d",&n) ) {
                if( n == -1 ) break;

                V.clear();
                memset( Neg , false , sizeof(Neg) );
                for( int i = 0; i < N; i++ ) graph[i].clear();

                for( int i = 1; i <= n; i++ ) {
                        int w;
                        scanf("%d",&w);
                        int k;
                        scanf("%d",&k);
                        while( k-- ) {
                               int u;
                               scanf("%d",&u);
                               V.push_back( Edge( i , u , -w ) );
                               graph[i].push_back( u );
                        }
                }
                if( BellmanFord( 1 ) ) cout << "winnable" << endl;
                else cout << "hopeless" << endl;

        }
        return 0;
}






