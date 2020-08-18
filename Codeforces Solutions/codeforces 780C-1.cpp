#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector <int> graph[ N ];
bool visited[ N ];
int color[ N ];
int parent[ N ];
int tot = 0;

void dfs( int s , int par ) {
    visited[ s ] = true;
    int col = 1;
    for( int i = 0; i < graph[ s ].size();i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            while( color[ s ] == col || color[ par ] == col ) {
                col ++;
            }
            color[ next ] = col;
            tot = max( tot , col );
            dfs( next  , s );
            col++;
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        int  u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    color[ 1 ] = 1;
    dfs( 1 , -1 );
    cout << tot << endl;
    for( int i = 1; i <= n ; i++ ) {
        cout << color[ i ] << " ";
    }
    cout << endl;
    return 0;
}
