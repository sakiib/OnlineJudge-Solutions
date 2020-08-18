#include <bits/stdc++.h>
using namespace std;

map <string,int> M;
vector <int> graph[ 300 ];
bool visited[ 300 ];

int dfs( int s ) {
    visited[ s ] = true;
    int mx = 0;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            int ans = dfs( next )+1;
            mx = max( mx , ans);
        }
    }
    return mx;
}
string process( string &str ) {
    for( int i = 0; i < str.size(); i++ ) {
        if( str[i] >= 'A' && str[i] <= 'Z' ) {
            str[i] -= 'A';
            str[i] += 'a';
        }
    }
    return str;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int id = 0;
    for( int i = 1; i <= n; i++ ) {
        string a, b, c;
        cin >> a >> b >> c;
        string x = process( a );
        string y = process( c );
        if( M[ x ] == 0 ) M[ x ] = ++id;
        if( M[ y ] == 0 ) M[ y ] = ++id;
        graph[ M[ y ] ].push_back( M[ x ] );
    }
    cout << dfs( M["polycarp"] )+1 << endl;
    return 0;
}
