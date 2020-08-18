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

int n , m;
int val[ 3*N ];
int visited[ 3*N ];
bool cycle = false;
vector <int> graph[ 3*N ];
int dp[ 3*N ][ 26 ];

void FindCycle( int s ) {
    if( visited[s] == 2 ) return;
    if( visited[s] == 1 ) {
        puts("-1");
        exit( 0 );
    }
    visited[s] = 1;
    for( auto x : graph[ s ] ) {
        FindCycle( x );
    }
    visited[s] = 2;
}
void dfsDP( int s ) {
    dp[s][val[s]] = 1;
    visited[s] = 1;
    for( auto x : graph[ s ] ) {
        if( !visited[x] ) dfsDP( x );
        for( int j = 1; j <= 26; j++ ) {
            dp[s][j] = max( dp[s][j] , dp[x][j]+( j == val[s] ) );
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m;
    string str;
    cin >> str;
    for( int i = 0; i < str.size(); i++ ) {
        val[i+1] = str[i]-'a'+1;
    }
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
    }
    for( int i = 1; i <= n; i++ ) {
        if( !visited[i] ) FindCycle( i );
    }
    memset( visited , 0 , sizeof(visited) );
    for( int i = 1; i <= n; i++ ) {
        if( !visited[i] ) dfsDP( i );
    }
    int mx = 0;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= 26; j++ ) {
            mx = max( mx , dp[i][j] );
        }
    }
    cout << mx << endl;
    return 0;
}

