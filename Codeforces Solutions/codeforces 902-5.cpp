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
int Start[ N ] , Finish[ N ];
int color[ N ];
int Time = 0;
int ans = 1;

void dfs( int s , int par ) {
    Start[ s ] = ++Time;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == par ) continue;
        dfs( next , s );
    }
    Finish[ s ] = Time;
}
void dfs1( int s , int par , int col ) {
    if( color[s] != col ) {
        Update( 1 , 1 , n , Start[s] , Finish[s] , color[s] );
        ans++;
    }
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( next == par ) continue;
        dfs1( next , s , )
    }

}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 2; i <= n; i++ ) {
        int p;
        cin >> p;
        graph[ i ].push_back( p );
        graph[ p ].push_back( i );
    }
    for( int i = 1; i <= n; i++ ) {
        cin >> color[i];
    }
    dfs( 1 , -1 );
    dfs1( 1 , -1 , color[1] );
    return 0;
}

