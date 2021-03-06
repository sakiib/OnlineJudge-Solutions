#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );
#define endl                   '\n'
#define ii                     pair< int, int >
#define iii                    pair< int, ii >
#define F                      first
#define S                      second
#define pb                     push_back
#define ll                     pair < LL, LL >
#define sc                     scanf
#define pf                     printf
#define min3(a, b, c)          min( a, min( b, c) )
#define clr( V )               V.clear( )
#define sz( V )                (int)V.size( )
#define min4(a, b, c, d)       min( min3( a, b, c),d )
#define Fix( x )               setprecision( x ) << fixed
#define SREV( V )              sort( V.rbegin() , V.rend() )
#define All( V )               V.begin(),V.end()
#define min5(a, b, c, d, e)    min( min4( a, b, c, d), e )
#define SORT( V )              sort( V.begin(), V.end() )
#define REV( V )               reverse( V.begin(), V.end() )
#define MEM( a, x )            memset( a, x, sizeof( a ) )
#define max3( a, b, c )        max( a, max( b, c) )
#define mp                     make_pair
#define pp                     pop_back
#define max4(a, b, c, d)       max( max3( a, b, c ), d )
#define RIGHTMOST              __builtin_ctzll
#define POPCOUNT               __builtin_popcountll
#define LEFTMOST( x )          ( 63-__builtin_clzll( x ) )
#define max5(a, b, c, d, e)    max( max4( a, b, c, d ), e )
#define SQ( x )                ( ( (x)*(x) ) )
#define CU( x )                ( (x)*(x)*(x) )
#define CLR( a, n )            for( int i = 0; i < n; i++ ) a[i].clear()
#define debug( x )             cerr << "X is : " << x << endl
#define FOR( i, a, b )         for( int i = a; i <= b; i++ )
#define ROF( i, b, a )         for( int i = b; i >= a; i-- )
#define REP( i, a )            for( int i = 0; i < a; i++ )
#define Read                   freopen( "input.txt", "r", stdin )
#define Write                  freopen( "output.txt", "w", stdout )
#define Fast                   ios_base :: sync_with_stdio( 0 ); cin.tie(NULL)
#define PQ( x )                priority_queue< x, vector< x >, greater< x > >
#define Unique( a )            sort( All(a) ), a.erase( unique( All(a) ), a.end() )
#define UB( a, key )           upper_bound( a.begin(), a.end(), key ) - a.begin()
#define LB( a, key )           lower_bound( a.begin(), a.end(), key ) - a.begin()

const int dx[] = { +1 , -1 , +0 , +0 };
const int dy[] = { +0 , +0 , +1 , -1 };
const int hx[] = { -2 , -2 , -1 , -1 , +1 , +1 , +2 , +2 };
const int hy[] = { +1 , -1 , +2 , -2 , +2 , -2 , +1 , -1 };
const int fx[] = { -1 , +0 , +1 , +0 , +1 , +1 , -1 , -1 , +0 };
const int fy[] = { +0 , -1 , +0 , +1 , +1 , -1 , +1 , -1 , +0 };

template < typename T > inline T GCD( T a , T b ) { a = abs(a) , b = abs(b); return !b ? a : GCD(b, a % b); }
template < typename T > inline T LCM( T x , T y ) { T g = GCD( x , y ); return x*y/g; }
template < typename T > inline T BigMod ( T b , T p , T mod ) { T res = 1%mod , x = b%mod; while( p ) { if( p&1 ) res = (res*x)%mod; x = (x*x)%mod; p >>= 1; } return res; }
template < typename T > inline T ModInv( T val , T mod ) { return BigMod( val , mod-2 , mod ); }
template < typename T > inline T bigmod ( T b , T p , T mod ) { if( p == 0 ) return 1; T x = bigmod( b , p/2 , mod ); x = ( x*x )%mod; if( p%2 == 1 ) x = ( b*x )%mod; return x; }
template < typename T > inline T NumDigit ( T num , T base ) { return ( (T)( log10((num) )/log10( (base) ) ) )+1; }
template < typename T > inline T Power ( T b , T p ) { T res = 1 , x = b; while( p ) { if( p&1 ) res = (res*x); x = (x*x); p >>=1; } return res; }
template < typename T > inline T IsPrime( T x ) { if( x < 2 ) return false; for( T i = 2; i*i <= x; i++ ) { if( x%i == 0 ) return false; } return true; }
template < typename T > inline T SumDigit( T x ) { T ret = 0; while( x ) { ret += x%10 , x /= 10; } return ret; }



vector < int > V[ 2*N ];
int cnt[ 100 ];
vector < int > ans[ 2*N ];
int id = 0;
bool used[ 2*N ];


bool ok( string str ) {
    bool on = false , of = false;
    for( int i = 1; i <= str.size()-2; i++ ) {
            if( str[i] == '1' ) {
                if( on ) return false;
                on = true;
                of = false;
            }
            else if( str[i] == '0' ) {
                if( of ) return false;
                of = true;
                on = false;
            }
    }
    return true;
}
int main( int argc , char const *argv[] ) {
    #ifdef Local_Test
    freopen( "Input.txt" , "r" , stdin );
    freopen( "Output.txt" , "w" , stdout );
    #endif // Local_Test

    string str;
    cin >> str;
    if( sz(str) == 1 ) {
        if( str[0] == '1' ) return pf("-1\n"),0;
        pf("1\n");
        pf("1 1\n");
        return 0;
    }
    for( int i = 0; i < str.size(); i++ ) {
        cnt[ str[i]-'0' ]++;
        V[ str[i]-'0' ].pb( i+1 );
    }
    while( true ) {
        if( cnt[0] < 2 || cnt[1] < 1 ) break;
        //int las = V[0][0];
        used[ V[0][0] ] = true;
        ans[++id].pb( V[0][0] );
        V[0].erase( V[0].begin() );
        //cout << "A" << endl;
        ans[id].pb( V[1][0] );
        used[ V[1][0] ] = true;
        int las = V[1][0];
        V[1].erase( V[1].begin() );
        //cout << "B" << endl;
        int pos = UB( V[0] , las );
        if( V[0][pos] <= las ) return pf("-1\n"),0;
        ans[id].pb( V[0][pos] );
        used[ V[0][pos]] = true;
        V[0].erase( V[0].begin()+pos );
        cnt[0] -=2 , cnt[1]--;
        //cout << "C" << endl;
    }
    if( cnt[1] >= 1 ) return pf("-1\n"),0;
    for( int i = 1; i <= sz(str); i++ ) {
        if( !used[i] ) {
            ans[++id].pb( i );
        }
    }
    pf("%d\n",id);
    for( int i = 1; i <= id; i++ ) {
        pf("%d ",sz(ans[i]));
        for( int j = 0; j < ans[i].size(); j++ ) {
            pf("%d ",ans[i][j]);
        }
        pf("\n");
    }
    return 0;
}

