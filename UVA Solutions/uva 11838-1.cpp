#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

vector <int> graph[ N ];
bool vis[ N ];

int dfs( int s ) {
        vis[s] = true;
        int ret = 0;
        for( auto x : graph[s] ) {
                if( !vis[x] ) {
                        ret += dfs( x ) + 1;
                }
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        int n , m;
        while( scanf("%d %d",&n,&m) ) {
                if( n == 0 && m == 0 ) break;
                for( int i = 1; i <= m; i++ ) {
                        int u , v , c;
                        scanf("%d %d %d",&u,&v,&c);
                        graph[u].push_back( v );
                        if( c == 2 ) graph[v].push_back( u );
                }
                bool f = true;
                for( int i = 1; i <= n; i++ ) {
                        memset( vis , false , sizeof(vis) );
                        int tot = dfs( i );
                        //cout << i << " " << tot << endl;
                        if( tot != n-1 ) {
                                f = false;
                                break;
                        }
                }
                if( f ) printf("1\n");
                else printf("0\n");
                for( int i = 1; i < N; i++ ) graph[i].clear();
        }
        return 0;
}






