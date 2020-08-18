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
int from[ N ] , to[ N ];
vector <int> ans;

void dfs( int s , int par , int level , int odd , int even ) {
    if( level&1 ) {
        odd %= 2;
        if( odd&1 ) from[s]  = !from[s];
    }
    else {
        even %= 2;
        if( even&1 ) from[s] = !from[s];
    }
    if( from[s] != to[s] ) {
        ans.push_back( s );
        if( level&1 ) odd++;
        else even++;
    }
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == par ) continue;
        dfs( next , s , level+1 , odd , even );
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    for( int i = 1; i <= n; i++ ) cin >> from[i];
    for( int i = 1; i <= n; i++ ) cin >> to[i];
    dfs( 1 , -1 , 1 ,  0 , 0 ); // start , parent , level , odd , even
    cout << ans.size() << endl;
    for( int i = 0; i < ans.size(); i++ ) cout << ans[i] << endl;
    return 0;
}

