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

vector <int> V;

bool Quasi( int x ) {
    while( x ) {
        int r = x%10;
        x /= 10;
        if( r != 1 && r != 0 ) return false;
    }
    return true;
}
void calc( ) {
    for( int i = 1; i <= 1000000; i++ ) {
        if( Quasi( i ) ) V.push_back( i );
    }
}

int n;
int dp[ 10*N ];

int solve( int n ) {
    if( n == 0 ) return 0;
    int mn = inf;
    if( dp[n] != -1 ) return dp[n];
    for( int i = 0; i < V.size(); i++ ) {
        if( n-V[i] >= 0 ) mn = min( mn , solve( n-V[i] )+1 );
    }
    return dp[n] = mn;
}
void path( int x ) {
    if( x == 0 ) return;
    int ret = dp[x];
    for( int i = 0; i < V.size(); i++ ) {
        if( x - V[i] >= 0 ) {
            if( ret == 1+solve( x-V[i]) ) {
                cout <<V[i] << " ";
                path( x-V[i] );
                return;
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    calc( );
    memset( dp , -1 , sizeof( dp ) );
    cout << solve( n ) << endl;
    path( n );
    return 0;
}

