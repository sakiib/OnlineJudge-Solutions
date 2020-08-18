#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
vector <int> graph[ N ];
int n , m , s;
bool visited[ N ];
bool good[ N ];
vector < pair <int , int> > V;

void mark_good( int s ) {
        good[s] = true;
        for( auto x : graph[s] ) if( !good[x] ) mark_good( x );
}
int dfs( int s ) {
        visited[s] = true;
        int ret = 0;
        for( auto x : graph[s] ) if( !visited[x] ) ret += dfs( x )+( good[x] == true ? 0 : 1 );
        return ret;
}
int main( int argc , char const *argv[] ) {
        cin >> n >> m >> s;
        for( int i = 1; i <= m; i++ ) {
                int u , v;
                cin >> u >> v;
                graph[u].push_back( v );
        }
        mark_good( s );
        for( int i = 1; i <= n; i++ ) {
                memset( visited , false , sizeof(visited) );
                if( !good[i] ) {
                        int cnt = 0;
                        cnt = dfs( i );
                        V.push_back( make_pair( cnt , i ) );
                }
        }
        sort( V.rbegin() , V.rend() );
        int ans = 0;
        for( int i = 0; i < V.size(); i++ ) {
                if( !good[ V[i].second ] ) {
                        ans++;
                        mark_good( V[i].second );
                }
        }
        cout << ans << endl;
        return 0;
}
