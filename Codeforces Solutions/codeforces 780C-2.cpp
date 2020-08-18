#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector < int > graph[ N ];
bool visited [ N ];
int color[ N ];
int tot = 0;

void dfs( int st , int par ) {
    visited [ st ] = true;
    int cur = 1;
    for ( int i = 0; i < graph[ st ].size(); i++ ) {
        while ( color[ st ] == cur || color[ par ] == cur ) {
            cur ++;
        }
        int next = graph[ st ][ i ];
        if ( !visited[ next ] ) {
            tot = max( tot , cur );
            color[ next ] = cur;
            dfs( next , st );
            cur ++;
        }
    }
}
int main( int argc , char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for ( int i = 1; i < n; i++ ) {
        int  u, v;
        scanf("%d%d",&u,&v);
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    color[ 1 ] = 1;
    dfs( 1 , 0);
    printf("%d\n",tot);
    for ( int i = 1; i <= n; i++ ) {
        printf("%d ",color[ i ]);
    }
    return 0;
}
