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
#define ff                     first
#define ss                     second
#define pb                     push_back
#define ll                     pair < LL, LL >
#define sc                     scanf
#define pf                     printf
#define Set( N , p )           N = ((N)((1LL)<<(p)))
#define Reset( N , p )         N = ((N)&(~((1LL)<<(p))))
#define Check( N , p )         (!(((N)&((1LL)<<(p)))==(0)))
#define clr( V )               V.clear( )
#define sz( V )                (int)V.size( )
#define Fix( x )               setprecision( x ) << fixed
#define SREV( V )              sort( V.rbegin() , V.rend() )
#define All( V )               V.begin(),V.end()
#define SORT( V )              sort( V.begin(), V.end() )
#define REV( V )               reverse( V.begin(), V.end() )
#define MEM( a, x )            memset( a, x, sizeof( a ) )
#define mp                     make_pair
#define pp                     pop_back
#define RIGHTMOST              __builtin_ctzll
#define POPCOUNT               __builtin_popcountll
#define LEFTMOST( x )          ( 63-__builtin_clzll( x ) )
#define SQ( x )                ( ( (x)*(x) ) )
#define CU( x )                ( (x)*(x)*(x) )
#define CLR( a, n )            for( int i = 0; i < n; i++ ) a[i].clear()
#define FOR( i, a, b )         for( int i = a; i <= b; i++ )
#define ROF( i, b, a )         for( int i = b; i >= a; i-- )
#define REP( i, a )            for( int i = 0; i < a; i++ )
#define Unique( a )            sort( All(a) ), a.erase( unique( All(a) ), a.end() )
#define UB( a, key )           upper_bound( a.begin(), a.end(), key ) - a.begin()
#define LB( a, key )           lower_bound( a.begin(), a.end(), key ) - a.begin()

const int dx[] = { +1 , -1 , +0 , +0 };
const int dy[] = { +0 , +0 , +1 , -1 };
const int hx[] = { -2 , -2 , -1 , -1 , +1 , +1 , +2 , +2 };
const int hy[] = { +1 , -1 , +2 , -2 , +2 , -2 , +1 , -1 };
const int fx[] = { -1 , +0 , +1 , +0 , +1 , +1 , -1 , -1 , +0 };
const int fy[] = { +0 , -1 , +0 , +1 , +1 , -1 , +1 , -1 , +0 };


bool EqualTo ( double a , double b ){ if ( fabs ( a - b ) <= EPS ) return true; else return false; }
bool NotEqual ( double a , double b ){ if ( fabs ( a - b ) > EPS ) return true; else return false; }
bool LessThan ( double a , double b ){ if ( a + EPS < b ) return true; else return false; }
bool LessThanEqual ( double a , double b ){ if ( a < b + EPS ) return true;   else return false;}
bool GreaterThan ( double a , double b ){ if ( a > b + EPS ) return true; else return false;}
bool GreaterThanEqual ( double a , double b ){ if ( a + EPS > b ) return true; else return false;}

template < typename T > inline T GCD( T a , T b ) { a = abs(a) , b = abs(b); return !b ? a : GCD(b, a % b); }
template < typename T > inline T LCM( T x , T y ) { T g = GCD( x , y ); return x*y/g; }
template < typename T > inline T BigMod ( T b , T p , T mod ) { T res = 1%mod , x = b%mod; while( p ) { if( p&1 ) res = (res*x)%mod; x = (x*x)%mod; p >>= 1; } return res; }
template < typename T > inline T ModInv( T val , T mod ) { return BigMod( val , mod-2 , mod ); }
template < typename T > inline T Bigmod ( T b , T p , T mod ) { if( p == 0 ) return 1; T x = bigmod( b , p/2 , mod ); x = ( x*x )%mod; if( p%2 == 1 ) x = ( b*x )%mod; return x; }
template < typename T > inline T NumDigit ( T num , T base ) { return ( (T)( log10((num) )/log10( (base) ) ) )+1; }
template < typename T > inline T Power ( T b , T p ) { T res = 1 , x = b; while( p ) { if( p&1 ) res = (res*x); x = (x*x); p >>=1; } return res; }
template < typename T > inline T IsPrime( T x ) { if( x < 2 ) return false; for( T i = 2; i*i <= x; i++ ) { if( x%i == 0 ) return false; } return true; }
template < typename T > inline T SumDigit( T x ) { T ret = 0; while( x ) { ret += x%10 , x /= 10; } return ret; }
template < typename T > inline T ExtGCD( T a , T b , T &x , T &y ) { if(b == 0) { x = 1; y = 0; return a; } T x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 ); x = y1; y = x1-(a / b)*y1; return gcd; }


LL n , k , m , d;

LL calc( LL dibo ) {
    LL t = n/(dibo*k);
    LL rem = n%(dibo*k);
    if( n%(dibo*k) != 0 && rem >= dibo ) t++;
    if( t > d ) return -INF;
    LL arc = t;
    //cout << dibo << " " << arc << endl;
    return ( arc*dibo );
}
LL TernarySearch( ) {
    LL lo = 1 , hi = m , ret = -1 , it = 500;
    LL mx = -1;
    while( hi-lo >= 5 ) {
        LL midL = ( 2*lo+hi )/3;
        LL midR = ( lo+2*hi )/3;
        LL left = calc( midL );
        LL right = calc( midR );
        if( left > right ) {
            mx = max( mx , left );
            hi = midR;
        }
        else lo = midL;
    }
    //cout << lo << " " << hi << endl;
    for( LL i = lo; i <= hi; i++ ) mx = max( mx , calc( i ) );
    return mx;
}
int main( int argc , char const *argv[] ) {
    cin >> n >> k >> m >> d;
    cout << calc( 8325624421831635 ) << endl;
    //cout << TernarySearch( ) << endl;
    return 0;
}


