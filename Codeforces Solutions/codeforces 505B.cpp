#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

vector <ii> graph[ 105 ];
bool visited[ 105 ];

void dfs( int s , int c , int d ) {
    visited[s] = true;
    if( s == d ) return;
    for( int i = 0; i < graph[s].size(); i++ ) {
        ii nxt = graph[s][i];
        int node = nxt.first;
        int col = nxt.second;
        if( !visited[node] && col == c ) {
            dfs( node , c , d );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ) {
        int u , v , c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
        graph[v].push_back({u,c});
    }
    int q;
    cin >> q;
    while( q-- ) {
        int x , y;
        cin >> x >> y;
        int ans = 0;
        for( int i = 1; i <= m; i++ ) {
            memset( visited , false , sizeof(visited) );
            dfs( x , i , y );
            if( visited[y] ) ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}

