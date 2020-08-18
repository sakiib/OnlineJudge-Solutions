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
vector <int> ans;
int dp[ 10*N ];

bool Quasi( int x ) {
    while( x ) {
        int rem = x%10;
        if( rem != 1 && rem != 0 ) return false;
        x /= 10;
    }
    return true;
}
void process( ) {
    for( int i = 1; i <= 1000000; i++ ) {
        if( Quasi( i ) ) V.push_back( i );
    }
}
int way( int n ) {
    if( n == 0 ) return 0;
    int mn = inf;
    if( dp[n] != -1 ) return dp[n];
    for( int i = 0; i < V.size(); i++ ) {
        if( n-V[i] >= 0 ) mn = min( mn , way( n-V[i])+1 );
    }
    return dp[n] = mn;
}
void path( int n ) {
    if( n == 0 ) return;
    int r = dp[n];
    for( int i = 0; i < V.size(); i++ ) {
        if( n-V[i] >= 0 ) {
            if( r == way( n-V[i] )+1 ) {
                ans.push_back( V[i] );
                path( n-V[i] );
                return;
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    process( );
    memset( dp , -1, sizeof( dp ) );
    cout << way( n ) << endl;
    path( n );
    for( auto x : ans ) cout << x << " ";
    return 0;
}

