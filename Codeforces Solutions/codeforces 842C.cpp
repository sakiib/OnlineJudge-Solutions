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
bool visited[ 2*N ];
vector <int> divisor;

void dfs( int s ) {
    visited[ s ] = true;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {

            dfs( next );
        }
    }
}
void calc( int n ) {
    int sq = sqrt( n );
    for( int i = 1; i <= sq; i++ ) {
        if( n%i == 0 ) {
            divisor.push_back( i );
            if( n/i != i ) divisor.push_back( n/i );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    calc( n );
    for( int i = 1; i <= n; i++ ) {
        cin >> val[i];
    }
    for( int i = 1; i < n; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    dfs( 1 );
    return 0;
}


