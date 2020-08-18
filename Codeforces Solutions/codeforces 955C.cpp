#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
#define ii                       pair < int, int >
#define iii                      pair < int, ii >
#define FOR( i, a, b )           for( int i = a; i <= b; i++ )
#define ROF( i, a, b )           for( int i = a; i >= b; i-- )
#define pb                       push_back
#define mp                       make_pair
#define line                     cerr << "***** here *****" << endl;
#define all( V )                 V.begin(), V.end()
#define Unique( a )              sort(all(a)),a.erase(unique(all(a)),a.end())
#define sc                       scanf
#define pf                       printf
#define Fix( x )                 setprecision( x ) << fixed
#define mem( a, x )              memset( a, x, sizeof( a ) )

vector < LL > V;

LL SQRT( LL n ) {
    LL lo = 0 , hi = 1000000000+5, ret = 0;
    while( lo <= hi ) {
        LL mid = ( lo+hi ) >> 1;
        if( mid*mid <= n ) {
            ret = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ret;
}
LL Power ( LL b , LL p ) {
    LL res = 1, x = b;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return ( res );
}
void precalc( ) {
    for( LL i = 2; i <= 1000000; i++ ) {
        LL sq = SQRT( i );
        if( sq*sq == i ) continue;
        for( LL j = 3; ; j++) {
            LL val = Power( i , j );
            if( val > INF || val <= 0 ) break;
            LL sq = sqrt( val );
            if( sq*sq == val ) continue;
            V.push_back( val );
        }
    }
    Unique( V );
    //for( int i = 0; i < 10; i++ ) cout << V[i] << " ";
    //cout << endl;
}
int main( int argc, char const *argv[] ) {

    precalc( );

    int q;
    cin >> q;
    while( q-- ) {
        LL l , r;
        cin >> l >> r;
        LL ans = SQRT( r ) - SQRT( l-1 );
        cout << ans << endl;
        LL b = upper_bound( all(V) , r ) - V.begin();
        LL a = lower_bound( all(V) , l ) - V.begin();
        ans += (b-a);
        cout << ans << endl;
    }
    return 0;
}





