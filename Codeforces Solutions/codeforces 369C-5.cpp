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

int n;
vector < int > graph[ N ];
int dist[ N ] , repair[ N ];
vector <int> V;

void dfs( int s , int p ) {
    if( repair[s] ) dist[s] = 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( next == p ) continue;
        dfs( next , s );
        dist[s] += dist[next];
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n-1; i++ ) {
        int u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back( v );
        graph[v].push_back( u );
        if( w == 2 ) repair[u] = repair[v] = 1;
    }
    dfs( 1 , -1 );
    for( int i = 1; i <= n; i++ ) {
        if( dist[i] == 1 ) V.push_back( i );
    }
    cout << V.size() << endl;
    for( auto x : V ) cout << x << " ";
    return 0;
}

