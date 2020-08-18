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
#define Set( N , p )           N=((N)((1LL)<<(p)))
#define Reset( N , p )         N=((N)&(~((1LL)<<(p))))
#define Check( N , p )         (!(((N)&((1LL)<<(p)))==(0)))
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
template < typename T > inline T Bigmod ( T b , T p , T mod ) { if( p == 0 ) return 1; T x = bigmod( b , p/2 , mod ); x = ( x*x )%mod; if( p%2 == 1 ) x = ( b*x )%mod; return x; }
template < typename T > inline T NumDigit ( T num , T base ) { return ( (T)( log10((num) )/log10( (base) ) ) )+1; }
template < typename T > inline T Power ( T b , T p ) { T res = 1 , x = b; while( p ) { if( p&1 ) res = (res*x); x = (x*x); p >>=1; } return res; }
template < typename T > inline T IsPrime( T x ) { if( x < 2 ) return false; for( T i = 2; i*i <= x; i++ ) { if( x%i == 0 ) return false; } return true; }
template < typename T > inline T SumDigit( T x ) { T ret = 0; while( x ) { ret += x%10 , x /= 10; } return ret; }
template < typename T > inline T ExtGCD( T a , T b , T &x , T &y ) { if(b == 0) { x = 1; y = 0; return a; } T x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 ); x = y1; y = x1-(a / b)*y1; return gcd; }


struct Matrix { LL M[ 10 ][ 10 ]; };

Matrix original;

LL mod;

Matrix MatrixMul( Matrix a , Matrix b  ) {
    Matrix temp;
    for( int i = 1; i <= 3; i++ ) {
        for( int j = 1; j <= 3; j++ ) {
            temp.M[i][j] = 0;
        }
    }
    for( int i = 1; i <= 3; i++ ) {
        for( int j = 1; j <= 3; j++ ) {
            for( int k = 1; k <= 3; k++ ) {
                temp.M[i][j] = (temp.M[i][j]%mod+(a.M[i][k]%mod*b.M[k][j]%mod)%mod)%mod;
            }
        }
    }
    return temp;
}
Matrix MatrixExpo( Matrix a , LL p ) {
    Matrix ret;
    if( p == 1 ) return a;
    ret = MatrixExpo( a , p/2 );
    if( p&1 ) return MatrixMul( MatrixMul( ret , ret ) , original );
    return MatrixMul( ret , ret );
}

int main( int argc , char const *argv[] ) {
    #ifdef Local_Test
    freopen( "Input.txt" , "r" , stdin );
    freopen( "Output.txt" , "w" , stdout );
    #endif // Local_Test

    int t;
    sc("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL a1 , b1 , c1 , a2 , b2 , c2;
        sc("%lld %lld %lld %lld %lld %lld",&a1,&b1,&c1,&a2,&b2,&c2);
        LL f0 , f1 , f2 , g0 , g1 , g2;
        sc("%lld %lld %lld %lld %lld %lld",&f0,&f1,&f2,&g0,&g1,&g2);
        sc("%lld",&mod);
        LL q;  sc("%lld",&q);
        pf("Case %d:\n",tc);
        while( q-- ) {
            LL n;  sc("%lld",&n);
            for( int i = 1; i <= 3; i++ ) {
                for( int j = 1; j <= 3; j++ ) {
                    original.M[i][j] = 0;
                }
            }
            if( n == 0 ) {
                pf("%lld %lld\n",f0%mod,g0%mod);
            }
            else if( n == 1 ) {
                pf("%lld %lld\n",f1%mod,g1%mod);
            }
            else if( n == 2 ) {
                pf("%lld %lld\n",f2%mod,g2%mod);
            }
            else {
                original.M[1][1] = a1 , original.M[1][2] = b1 , original.M[1][3] = c1;
                original.M[2][1] = 1 , original.M[3][2] = 1;

                Matrix resf = MatrixExpo( original , n-2 );
                //cout << "f done " << endl;

                for( int i = 1; i <= 3; i++ ) {
                for( int j = 1; j <= 3; j++ ) {
                    original.M[i][j] = 0;
                }
               }
                original.M[1][1] = a2 , original.M[1][2] = b2 , original.M[1][3] = c2;
                original.M[2][1] = 1 , original.M[3][2] = 1;

                Matrix resg = MatrixExpo( original , n-2 );
                //cout << " g done" << endl;
                LL f = ( (resf.M[1][1]%mod*f2%mod)%mod+(resf.M[1][2]%mod*f1%mod)%mod+(resf.M[1][3]%mod*f0%mod)%mod)%mod;
                LL g = ( (resg.M[1][1]%mod*g2%mod)%mod+(resg.M[1][2]%mod*g1%mod)%mod+(resg.M[1][3]%mod*g0%mod)%mod)%mod;
                pf("%lld %lld\n",f%mod,g%mod);
            }
        }
    }
    return 0;
}


