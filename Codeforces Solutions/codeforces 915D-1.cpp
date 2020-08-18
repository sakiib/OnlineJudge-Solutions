#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int color[ N ];
int parent[ N ];
vector <int> graph[ N ];
vector < pair<int,int> > CycleEdge;
bool found;

void FindCycle( int s ) {
    color[s] = 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( CycleEdge.size() ) return;
        if( color[next] == 1 ) {
            int k = s;
            CycleEdge.push_back( { k , next } );
            while( parent[k] != next ) {
                CycleEdge.push_back( { parent[k] , k } );
                k = parent[k];
            }
            CycleEdge.push_back( { next , k } );
            return;
        }
        else if( color[next] == 0 ) {
            parent[next] = s;
            FindCycle( next );
        }
    }
    color[s] = 2;
}
void dfs( int s , int u , int v ) {
    color[s] = 1;
    if( found ) return;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( s == u && next == v ) continue;
        if( color[next] == 1 ) {
            found = true;
            return;
        }
        else if( color[next] == 0 ) dfs( next , u , v );
    }
    color[s] = 2;
}
int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
    }
    for( int i = 1; i <= n; i++ ) {
        if( color[i] == 0 ) FindCycle( i );
        if( CycleEdge.size() ) break;
    }
    if( !CycleEdge.size() ) return cout << "YES" << endl , 0;
    for( int i = 0; i < CycleEdge.size(); i++ ) {
        memset( color , 0 , sizeof( color ) );
        int x = CycleEdge[i].first;
        int y = CycleEdge[i].second;
        found = false;
        for( int j = 1; j <= n; j++ ) {
            if( color[j] == 0 ) dfs( j , x , y );
            if( found ) break;
        }
        if( !found ) return cout << "YES" << endl , 0;
    }
    cout << "NO" << endl;
    return 0;
}

