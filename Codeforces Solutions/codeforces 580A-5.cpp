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

int ara[ N ];
int mx = 0;
int n;

void solve( int id , int last , int taken ) {
    mx = max( mx , taken );
    if( id > n ) return;
    if( ara[id] >= last ) solve( id+1 , ara[id] , taken+1 );
    else solve( id , 0 , 0 );
}
int main( int argc, char const *argv[] ) {

    cin >> n;
    FOR( i , 1 , n ) cin >> ara[i];
    solve( 1 , 0 , 0 );
    cout << mx << endl;
    return 0;
}






