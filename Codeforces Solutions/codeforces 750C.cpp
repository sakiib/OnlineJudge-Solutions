#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector <int> graph[ N ];
int parent[ N ];

void makeset( int n ) {
    for( int i = 1; i <= n; i++ ) {
        parent[ i ] = i;
    }
}
int Find( int x ) {
    return (parent[ x ] == x ? x : parent[ x ] = Find( parent[ x ]) );
}
void Union( int x , int y ) {
    int a = Find( x );
    int b = Find( y );
    if( a != b ) parent[ b ] = a;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    makeset( n );
    for( int i = 1; i <= n; i++ ) {
        int node;
        cin >> node;
        if( Find( i ) != Find( node ) ) {
            Union( i , node );
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; i++ ) {
        if( parent[ i ] == i ) ans ++;
    }
    cout << ans << endl;
    return 0;
}

