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

vector < int > graph[ N ];
int color[ N ];
vector < ii > edge;

bool dfs( int s , int p ) {

}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i < n; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v );
        graph[v].push_back( u );
        edge.push_back( {u,v} );
    }
    for( int i = 1; i <= n; i++ ) scanf("%d",&color[i]);
    for( int i = 0; i < edge.size(); i++ ) {
        int a = edge[i].first;
        int b = edge[i].second;
        for( int j = 0; j < graph[a].size(); j++ ) {
            if( dfs( a , ))
        }
        for( int j = 0; j < graph[b].size(); j++ ) {

        }
    }
    printf("No\n");
    return 0;
}

