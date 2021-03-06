#include <bits/stdc++.h>
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
#define Fix( x )               setprecision( x ) << fixed
#define MEM( a, x )            memset( a, x, sizeof( a ) )
#define mp                     make_pair
#define RIGHTMOST              __builtin_ctzll
#define POPCOUNT               __builtin_popcountll
#define LEFTMOST( x )          ( 63-__builtin_clzll( x ) )
#define SQ( x )                ( ( (x)*(x) ) )
#define CU( x )                ( (x)*(x)*(x) )
#define sz( V )                (int)( V.size() )
#define CLR( V )               V.clear()
#define SREV( V )              sort( V.rbegin() , V.rend() )
#define REV( V )               reverse( V.begin() , V.end() )
#define SORT( V )              sort( V.begin() , V.end() )
#define All( V )               V.begin(), V.end()
#define Unique( a )            sort( All(a) ), a.erase( unique( All(a) ), a.end() )
#define UB( a, key )           upper_bound( a.begin(), a.end(), key ) - a.begin()
#define LB( a, key )           lower_bound( a.begin(), a.end(), key ) - a.begin()

const int dx[] = { +1 , -1 , +0 , +0 };
const int dy[] = { +0 , +0 , +1 , -1 };
const int hx[] = { -2 , -2 , -1 , -1 , +1 , +1 , +2 , +2 };
const int hy[] = { +1 , -1 , +2 , -2 , +2 , -2 , +1 , -1 };
const int fx[] = { -1 , +0 , +1 , +0 , +1 , +1 , -1 , -1 , +0 };
const int fy[] = { +0 , -1 , +0 , +1 , +1 , -1 , +1 , -1 , +0 };
const int month[] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
const int monthL[] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

int  Set( int N , int pos )    { return N = N | ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

bool EqualTo( double a , double b ){ if ( fabs ( a - b ) <= EPS ) return true; else return false; }
bool NotEqual( double a , double b ){ if ( fabs ( a - b ) > EPS ) return true; else return false; }
bool LessThan( double a , double b ){ if ( a + EPS < b ) return true; else return false; }
bool LessThanEqual( double a , double b ){ if ( a < b + EPS ) return true;   else return false; }
bool GreaterThan( double a , double b ){ if ( a > b + EPS ) return true; else return false; }
bool GreaterThanEqual( double a , double b ){ if ( a + EPS > b ) return true; else return false; }

bool isLeap( int year ) { if( ( year%400 == 0 || year%100 != 0 ) &&( year%4 == 0 ) ) return true; return false; }
string DecToBin( int x ) { string s = ""; while( x ) { s += (x%2)+'0'; x /= 2; } reverse( s.begin() , s.end() ); while( s.size() < 32 ) s = '0'+s; return s; }
int BinToDec( string s ) { int ret = 0 , base = 1; for( int i = s.size()-1; i >= 0; i-- ) { if( s[i] == '1' ) ret += base; base *= 2; } return ret; }
int StringMod( string str , int mod ) { int temp = 0; for( int i = 0; i < str.size(); i++ ) { temp = ( temp*10+( str[i]-'0' ) )%mod; } return temp; }
bool isPalin( string s ) { int l = s.size(); for( int i = 0; i < l/2; i++ ) { if( s[i] != s[l-1-i] ) return false; } return true; }
int StrToInt( string s ) { stringstream ss( s ); int num; ss >> num; return num; }
string IntToStr( int n ) { string s = ""; stringstream conv; conv << n; s = conv.str( ); return s; }

template < typename T > inline T GCD( T a , T b ) { a = abs(a) , b = abs(b); return !b ? a : GCD(b, a % b); }
template < typename T > inline T LCM( T x , T y ) { T g = GCD( x , y ); return x*y/g; }
template < typename T > inline T BigMod ( T b , T p , T mod ) { T res = 1%mod , x = b%mod; while( p ) { if( p&1 ) res = (res*x)%mod; x = (x*x)%mod; p >>= 1; } return res; }
template < typename T > inline T ModInv( T val , T mod ) { return BigMod( val , mod-2 , mod ); }
template < typename T > inline T Bigmod ( T b , T p , T mod ) { if( p == 0 ) return 1; T x = Bigmod( b , p/2 , mod ); x = ( x*x )%mod; if( p%2 == 1 ) x = ( b*x )%mod; return x; }
template < typename T > inline T NumDigit ( T num , T base ) { return ( (T)( log10((num) )/log10( (base) ) ) )+1; }
template < typename T > inline T Power ( T b , T p ) { T res = 1 , x = b; while( p ) { if( p&1 ) res = (res*x); x = (x*x); p >>=1; } return res; }
template < typename T > inline T IsPrime( T x ) { if( x < 2 ) return false; for( T i = 2; i*i <= x; i++ ) { if( x%i == 0 ) return false; } return true; }
template < typename T > inline T SumDigit( T x ) { T ret = 0; while( x ) { ret += x%10 , x /= 10; } return ret; }
template < typename T > inline T ExtGCD( T a , T b , T &x , T &y ) { if(b == 0) { x = 1; y = 0; return a; } T x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 ); x = y1; y = x1-(a / b)*y1; return gcd; }


int n , m , k;
LL val[ 19 ];
LL add[ 19 ][ 19 ];
LL dp[ 1 << 18 + 1 ][ 19 ];

LL solve( int mask , int last ) {
    if( __builtin_popcount( mask ) == m ) return 0;
    if( dp[mask][last] != -1 ) return dp[mask][last];
    LL ret = 0;
    for( int i = 1; i <= n; i++ ) {
        if( !Check( mask , i-1 ) ) {
            ret = max( ret , solve( Set( mask , i-1 ) , i )+add[i][last]+val[i] );
        }
    }
    return dp[mask][last] = ret;
}
int main( int argc, char const *argv[] ) {
    scanf("%d %d %d",&n,&m,&k);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&val[i]);
    for( int i = 1; i <= k; i++ ) {
        int x , y;
        LL c;
        scanf("%d %d %lld",&x,&y,&c);
        add[y][x] = c;
    }
    memset( dp , -1 , sizeof(dp) );
    printf("%lld\n",solve( 0 , 0 ) ) ;
    return 0;
}

