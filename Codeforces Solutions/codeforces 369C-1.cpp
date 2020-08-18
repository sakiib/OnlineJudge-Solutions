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

vector <int> graph[ N ];
int has[ N ];
int val[ N ];
vector <int> ans;

void dfs( int s , int par ) {
    if( has[ s ] == 1 ) val[ s ] = 1;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == par ) continue;
        dfs( next , s );
        val[ s ] += val[ next ];
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        int u , v , c;
        cin >> u >> v >> c;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
        if( c == 2 ) has[ u ] = has[ v ] = 1;
    }
    dfs( 1 , 0 );
    for( int i = 1; i <= n; i++ ) {
        if( val[i] == 1 ) ans.push_back( i );
    }
    cout << ans.size() << endl;
    for( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

