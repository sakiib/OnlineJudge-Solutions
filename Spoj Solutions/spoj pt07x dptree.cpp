#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;

const int N = 100005;

vector <int> graph[ N ];
bool visited[ N ];
int sum[ N ];
int n;

void dfs( int s , int par ) {
    visited[s] = true;
    sum[s] = 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        int next = graph[s][i];
        if( !visited[next] ) {
            dfs( next , s );
            sum[s] += sum[next];
        }
    }
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    for( int i = 1; i < n; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    memset( visited , false , sizeof(visited) );
    memset( sum , 0 , sizeof(sum) );
    if( n == 1 ) return printf("0\n"),0;
    dfs( 1 , 0 );
    int ans = 0;
    for( int  i = 1; i <= n; i++ ) if( sum[i] != 1 ) ans++;
    printf("%d\n",ans);
    return 0;
}



