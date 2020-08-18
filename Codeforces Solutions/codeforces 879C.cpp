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


int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int tot = 0;
    FOR( i, 1, n ) {
        string s;
        int val;
        cin >> s >> val;
        if( s[0] == '|' ) tot |= val;
        if( s[0] == '^' ) tot ^= val;
        if( s[0] == '&' ) tot &= val;
    }
    if( tot == 0 ) return cout << 0 << endl,0;
    cout << tot << endl;

    return 0;
}






