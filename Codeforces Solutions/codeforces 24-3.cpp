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

const int sz = 105;

vector <ii> graph[ sz ];
int ans = 0;

void dfs( int s ,int p ) {
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        ii next = graph[ s ][ i ];
        int node = next.first;
        int cost = next.second;
        if( node == p ) continue;
        ans += cost;
        dfs( node , s );
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        int u , v , w;
        cin >> u >> v >> w;
        graph[ u ].push_back( {v,0} );
        graph[ v ].push_back( {u,w} );
    }
    dfs( 1 , -1 );
    cout << ans << endl;
    return 0;
}

