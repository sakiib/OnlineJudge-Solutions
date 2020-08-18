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

vector < int > graph[ 3*N ];
int cost[ 3*N ];
vector < int > V;

void bfs( int s ) {
    memset( cost , -1 , sizeof(cost) );
    queue < int > Q;
    Q.push( s );
    cost[s] = 0;
    while( !Q.empty( ) ) {
        int f = Q.front();
        Q.pop();
        for( int i = 0; i < graph[f].size(); i++ ) {
            int next = graph[f][i];
            if( cost[next] == -1 || cost[next] > cost[f]+1 ) {
                cost[next] = cost[f]+1;
                Q.push( next );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int s , n , e;
    cin >> s >> n >> e;
    for( int i = 1; i <= e; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    bfs( n );
    int mx = -inf;
    for( int i = 1; i <= s; i++ ) {
        V.push_back( cost[i] ) ;
        mx = max( mx , cost[i] );
    }
    int ans = 0;
    for( int i = 0; i < V.size(); i++ ) if( mx == V[i] ) ans++;
    cout << ans << endl;
    return 0;
}

