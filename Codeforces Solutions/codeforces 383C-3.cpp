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

int val[ 2*N ];
vector <int> graph[ 2*N ];
int Start[ 2*N ] , Finish[ 2*N ] , Level[ 2*N ];
bool visited[ 2*N ];
int BIT[ 2*N ];
int Time;

void dfs( int s ) {
    visited[ s ] = true;
    Start[ s ] = ++Time;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            Level[ next ] = Level[ s ]+1;
            dfs( next );
        }
    }
    Finish[ s ] = Time;
}
int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ) {
        cin >> val[i];
    }
    for( int i = 1; i < n; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    Time = 0;
    dfs( 1 );
    while( m-- ) {
        int op;
        cin >> op;
        if( op == 1 ) {
            int node , val;
            cin >> node >> val;
        }
        else {
            int node;
            cin >> node;
        }
    }
    return 0;
}




