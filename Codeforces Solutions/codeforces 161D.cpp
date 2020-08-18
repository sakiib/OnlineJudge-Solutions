#include <bits/stdc++.h>

using namespace std;

int n , k;
int dp[ 50005 ][ 505 ];
vector <int> graph[ 50005 ];
long long ans;

void dfs( int s , int p ) {
    dp[s][0] = 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( next == p ) continue;
        dfs( next , s );
        for( int j = 1; j <= k; j++ ) ans += ( dp[s][j-1]*dp[next][k-j] );
        for( int j = 1; j <= k; j++ ) dp[s][j] += dp[next][j-1];
    }
}
int main( int argc, char const *argv[] ) {
    scanf("%d %d",&n,&k);
    for( int i = 1; i < n; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    dfs( 1 , 0 );
    printf("%lld\n",ans);
    return 0;
}



