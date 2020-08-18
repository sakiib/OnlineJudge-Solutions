#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e3 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
int curEdge[ N ];
bool visited[ N ];
vector < pair <int,int> > graph[ N ];

vector <int> EulerPathUndirected( int u , int Edges ) {
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
vector <int> EulerPathUndirected( ) {
        int u = -1 , Edges = 0;
        for( int i = 1; i <= n; i++ ) {
                if( graph[i].size() > 0 && graph[i].size()%2 == 0 && u == -1 ) {
                        u = i;
                }
                if( graph[i].size()%2 == 1 ) return {};
                Edges += (int)( graph[i].size() );
        }
        return EulerPathUndirected( u , Edges/2 );
}
void Reset( ) {
        for( int i = 1; i < N; i++ ) graph[i].clear();
        memset( visited , false , sizeof( visited ) );
        memset( curEdge , 0 , sizeof( curEdge ) );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                Reset( );
                cin >> n;
                int id = 0;
                for( int i = 1; i <= n; i++ ){
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( {v,++id} );
                        graph[v].push_back( {u,++id} );
                }
                vector <int> V = EulerPathUndirected( );

                if( !V.size() ) {
                        cout << "Case " << "#" << tc << endl;
                        cout << "some beads may be lost" << endl;
                }
                else {
                        cout << "Case " << "#" << tc << endl;
                        for(int i = 0; i < V.size() - 1; i++ ) {
                                cout << V[i] << " " << V[i+1] << endl;
                        }
                }
        }
        return 0;
}
















