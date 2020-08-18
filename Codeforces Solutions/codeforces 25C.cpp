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

const int sz = 305;

int cost[ sz ][ sz ];
int n;
vector <int> V;

/*
void Floyd_Warshall( ) {
    for( int k = 1; k <= n; k++ ) {
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j] );
            }
        }
    }
    for( int i = 1; i <= n; i++ ) {
        for( int j = i+1 ; j <= n; j++ ) {
            ans += cost[i][j];
        }
    }
}*/
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            cin >> cost[i][j];
        }
    }
    int q;
    cin >> q;
    LL ans = 0;
    while( q-- ) {
        int u , v , w;
        cin >> u >> v >> w;
        ans = 0;
        //Floyd_Warshall( );
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                cost[i][j] = min( cost[i][j] , cost[i][u]+cost[v][j]+w );
                cost[i][j] = min( cost[i][j] , cost[i][v]+cost[u][j]+w );
            }
        }
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                ans += cost[i][j];
            }
        }
        V.push_back( ans/2 );
    }
    for( auto x : V ) cout << x << " ";
    return 0;
}

