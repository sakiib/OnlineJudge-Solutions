#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector <int> graph[ N ];
bool visited[ N ];
int color[ N ];
int ans = 1;

void dfs( int s , int cur ) {
    visited[ s ] = true;
    color[ s ] = cur;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            if( color[ next ] == cur ) dfs( next , cur );
            else {
               ans++;
               dfs( next , color[ next ] );
            }
        }
    }
}
int main( int argc , char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 2; i <= n; i++ ) {
        int v;
        cin >> v;
        graph[ i ].push_back( v );
        graph[ v ].push_back( i );
    }
    for( int i = 1; i<= n; i++ ) {
        cin >> color[i];
    }
    dfs( 1 , color[1] );
    cout << ans <<endl;
    return 0;
}

