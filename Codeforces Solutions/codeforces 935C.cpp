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


struct Point { double x , y; };

double R;
Point center = {0.0 , 0.0} , laptop = {0.0 , 0.0};


double Distance( Point center , Point laptop ) {
    double dist = sqrt( SQ( center.x-laptop.x ) + SQ( center.y-laptop.y ) );
    return dist;
}
bool OutsideFlat( ) {
    double d = Distance( center , laptop );
    if( d > R ) return true;
    return false;
}
pair < Point , Point > LineCircleIntersect( Point center , double r , Point P1 , Point P2 ) {
    double a1 = P2.x - P1.x;
    double a2 = P2.y - P1.y;
    double b1 = P1.x - center.x;
    double b2 = P1.y - center.y;
    // Function from flash7..
    // At^2 + Bt + C = 0
    double A = SQ(a1) + SQ(a2);
    double B = (a1*b1 + a2*b2)*2;
    double C = SQ(b1) + SQ(b2) - SQ(r);

    /// The line intersect the circle at two points
    double b4ac = abs(B*B - 4.0*A*C);
    double t1 = (-B - sqrt(b4ac))/2.0/A;
    double t2 = (-B + sqrt(b4ac))/2.0/A;

    Point E1 = {P1.x + a1*t1, P1.y + a2*t1};
    Point E2 = {P1.x + a1*t2, P1.y + a2*t2};
    return mp(E1,E2);
}
int main( int argc , char const *argv[] ) {
    #ifdef Local_Test
    freopen( "Input.txt" , "r" , stdin );
    freopen( "Output.txt" , "w" , stdout );
    #endif // Local_Test

    cout << Fix(10);

    cin >> R >> center.x >> center.y >> laptop.x >> laptop.y;
    if( OutsideFlat( ) ) {
        cout << center.x << " " << center.y << " " << R << endl;
        return 0;
    }
    Point an = laptop;
    if( center.x == laptop.x && center.y == laptop.y ) an = { center.x , INF };
    pair < Point , Point > P = LineCircleIntersect( center , R , center , an  );
    double d1 = Distance( P.F , laptop );
    double d2 = Distance( P.S , laptop );
    Point k = { 0.0 , 0.0 };
    if( d1 > d2 ) k = P.F;
    else k = P.S;
    Point mid = { 0.0 , 0.0 };
    mid.x = ( laptop.x+k.x )/2.0;
    mid.y = ( laptop.y+k.y )/2.0;
    double rad = Distance( mid , laptop );
    cout << mid.x << " " << mid.y << " " << rad << endl;
    return 0;
}









