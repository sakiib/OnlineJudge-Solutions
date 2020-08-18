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

int n , en;
bool visited[ N ];
vector <int> graph[ N ];

bool bfs( ) {
    queue <int> Q;
    Q.push( 1 );
    while( !Q.empty( ) ) {
        int f = Q.front();
        visited[ f ] = true;
        if( visited[ en ] ) return true;
        Q.pop();
        for( int i = 0; i < graph[ f ].size(); i++ ) {
            int next = graph[ f ][ i ];
            if( !visited[ next ] && next <= en ) {
                Q.push( next );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n >> en;
    for( int i = 1; i <= n-1; i++ ) {
        int val;
        cin >> val;
        graph[i].push_back( i+val );
    }
    if( bfs( ) ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

