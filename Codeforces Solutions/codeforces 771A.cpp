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

vector<LL> graph[ 15*N ];
bool visited[ 15*N ];
LL node , total;

void dfs( int s ) {
    node++;
    visited[s] = true;
    for( int i = 0; i < graph[s].size(); i++ ) {
        LL next = graph[s][i];
        if( !visited[next] ) {
            dfs( next );
        }
    }
}
int main( int argc, char const *argv[] ) {
    LL n , m;
    cin >> n >> m;
    for( int i = 1; i <= m; i++ ) {
        LL u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for( int i = 1; i <= n; i++ ) {
        if( !visited[i] ) {
            node = 0;
            dfs( i );
            total += (node*(node-1)/2);
        }
    }
    cout << ( total == m ? "YES" : "NO" ) <<endl;
    return 0;
}

