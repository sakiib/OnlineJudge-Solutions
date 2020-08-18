#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
vector < pair <int,int> > graph[ N ];
int curEdge[ N ];
bool visited[ N ];
priority_queue <int,vector <int>,greater <int>> Q[ 50 ][ 50 ];

vector <int> EulerCycleUndirected( int u , int Edges ) {
        vector <int> res;
        stack <int> S;
        S.push( u );
        while( !S.empty() ) {
                u = S.top(); S.pop();
                while( curEdge[u] < (int)( graph[u].size() ) ) {
                        pair <int,int> node = graph[u][curEdge[u]++];
                        int v = node.first , id = node.second;
                        if( !visited[id] ) {
                                S.push( u ) , u = v , visited[id] = true;
                        }
                }
                res.push_back( u );
        }
        if( (int)res.size() != Edges + 1 ) return {};
        reverse( res.begin() , res.end() );
        return res;
}
vector <int> EulerCycleUndirected( ) {
        int startingNode = -1 , totalEdges = 0;
        for( int i = 1; i <= 1995; i++ ) {
                if( (int)graph[i].size() > 0 && (int)graph[i].size()%2 == 0 && startingNode == -1 ) {
                        startingNode = i;
                }
                if( (int)graph[i].size()%2 == 1 ) return {};
                totalEdges += (int)graph[i].size();
        }
        if( startingNode == -1 ) return {};
        return EulerCycleUndirected( startingNode , totalEdges/2 );
}
void Reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( visited , false , sizeof( visited ) );
        memset( curEdge , 0 , sizeof( curEdge ) );
        for( int i = 1; i < 50; i++ ) {
                for( int j = 1; j < 50; j++ ) {
                        while( !Q[i][j].empty() ) Q[i][j].pop();
                }
        }
}
bool cmp( pair <int,int> a , pair <int,int> b ) {
        return a.second < b.second;
}
int main( int argc , char const *argv[] ) {
        int u , v , w;
        while( scanf("%d %d",&u,&v) ) {
                if( u == 0 && v == 0 ) break;
                Reset( );
                scanf("%d",&w);
                graph[u].push_back( {v,w} );
                graph[v].push_back( {u,w} );
                if( u > v ) swap( u , v );
                Q[u][v].push( w );
                //Q[v][u].push( w );
                while( scanf("%d %d",&u,&v) ) {
                        if( u == 0 && v == 0 ) break;
                        scanf("%d",&w);
                        graph[u].push_back( {v,w} );
                        graph[v].push_back( {u,w} );
                        if( u > v ) swap( u , v );
                        Q[u][v].push( w );
                        //Q[v][u].push( w );
                }
                for( int i = 1; i <= 1995; i++ ) sort( graph[i].begin() , graph[i].end() , cmp );
                vector <int> V = EulerCycleUndirected( );
                if( !V.size() ) {
                        printf("Round trip does not exist.\n");
                        printf("\n");
                        continue;
                }
                //for( auto x : V ) cout << x << " "; cout <<endl;
                for(int i = 0; i < V.size() - 1; i++ ) {
                        //cout << V[i] << " " << V[i+1] << endl;
                        int u = V[i] , v = V[i+1];
                        if( u > v ) swap( u , v );
                        if( i == 0 ) printf("%d",Q[u][v].top());
                        else  printf(" %d",Q[u][v].top());
                        Q[u][v].pop();
                }
                printf("\n\n");
        }
        return 0;
}















