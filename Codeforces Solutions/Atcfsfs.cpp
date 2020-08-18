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
bool f = true;

int dfs( int s , int par ) {
    if( graph[ s ].size() == 0 ) return 1;
    int res = 0;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == par ) continue;
        res += dfs( next , s );
    }
    if( res < 3 ) f = false;
    return 0;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 2; i <= n; i++ ) {
        int x;
        cin >> x;
        graph[ x ].push_back( i );
    }
    dfs( 1 , -1 );
    cout << ( f ? "Yes" : "No" ) <<endl;
    return 0;
}
