#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
bool invalid[ N ][ N ];
bool f = true;
vector <pair<int,int> > edge;
int  n , m;

void dfs( int root , int add ) {
    if( add > n ) return;
    if( invalid[ root ][ add ] ) {
        f = false;
        return;
    }
    if( root != add ) edge.push_back( {root,add} );
    dfs( root , add+1 );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m;
    for(int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        invalid[ u ][ v ] = true;
        invalid[ v ][ u ] = true;
    }
    for( int i = 1; i <=n ; i++ ) {
        edge.clear();
        f = true;
        dfs( i , 1 );
        if( f ) break;
    }
    cout << (n-1) <<endl;
    for( auto x : edge ) cout << x.first << " " << x.second <<endl;
    return 0;
}
