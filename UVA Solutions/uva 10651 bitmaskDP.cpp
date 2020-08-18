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

#define checkbit( N , p )   (!(((N)&((1LL)<<(p)))==(0)))
#define ON( n , b )         ( n = n | ( 1 << b ) )
#define OFF( n , b )        ( n = n & ~( 1 << b ) )

string s;
int dp[ 1 << 12 ];

int solve( int mask ) {
    if( dp[mask] != -1 ) return dp[mask];
    int ret = __builtin_popcount( mask );
    for( int i = 0; i < s.size(); i++ ) {
        if( i <= 9 && checkbit( mask , i ) && checkbit( mask , i+1 ) && !checkbit( mask , i+2 ) ) {
            int cur = mask;
            ON( cur , i+2 );
            OFF( cur , i+1 );
            OFF( cur , i );
            ret = min( ret , solve( cur ) );
        }
        if( i >= 2 && !checkbit( mask , i-2 ) && checkbit( mask , i-1 ) && checkbit( mask , i ) ) {
            int cur = mask;
            ON( cur , i-2 );
            OFF( cur , i-1 );
            OFF( cur , i );
            ret = min( ret , solve( cur ) );
        }
    }
    return dp[mask] = ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> s;
        int mask = 0;
        for( int i = 0; i < s.size(); i++ ) {
            if( s[i] == 'o' ) ON( mask , i );
        }
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( mask ) << endl;
    }
    return 0;
}

