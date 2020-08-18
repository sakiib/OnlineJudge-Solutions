#include <bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , m;
vector <int> graph[ 3*N ];
string str;
int color[ 3*N ];
int res[ 3*N ][ 30 ];
int val[ 3*N ];

void iscycle( int s ) {
    if( color[s] == 2 ) return;
    if( color[s] == 1 ) {
        cout << -1 << endl;
        exit(0);
    }
    color[s] = 1;
    for( auto x : graph[s] ) iscycle( x );
    color[s] = 2;
}
void dfs( int s ) {
    res[s][ val[s] ] = 1;
    color[s] = 1;
    for( auto x : graph[s] ) {
        if( color[x] == 0 ) dfs( x );
        for( int i = 1; i <= 26; i++ ) {
            res[s][i] = max( res[s][i] , res[x][i] + (i == (val[s])));
        }
    }
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    cin >> str;
    for( int i = 0; i < str.size(); i++ ) val[i+1] = str[i]-'a'+1;
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
    }
    memset( color , 0 , sizeof(color) );
    for( int i = 1; i <= n; i++ ) if( color[i] == 0 ) iscycle( i );
    memset( color , 0 , sizeof(color) );
    for( int i = 1; i <= n; i++ ) if( color[i] == 0 ) dfs( i );
    int mx = 0;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= 26; j++ ) {
            mx = max( mx , res[i][j] );
        }
    }
    cout << mx << endl;
    return 0;
}








