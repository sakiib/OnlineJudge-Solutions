#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

bool invalid[ N ][ N ];

int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        invalid[u][v] = true;
        invalid[v][u] = true;
    }
    vector < pair<int,int> > edge;
    for( int i = 1; i <= n; i++ ) {
        int root = i;
        bool f = true;
        edge.clear();
        for(int j = 1; j <= n; j++ ) {
            if( root == j) continue;
            if(invalid[ root ][ j ]) {
                f = false;
                break;
            }
            else edge.push_back( {root,j} );
        }
        if( f ) break;
    }
    cout << edge.size() <<endl;
    for( int i = 0; i < edge.size(); i++ ) {
        cout << edge[i].first << " " << edge[i].second <<endl;
    }
    return 0;
}
