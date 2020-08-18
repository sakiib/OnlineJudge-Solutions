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
#define SREV( V )              sort( V.rbegin() , V.rend() )
#define All( V )               V.begin(),V.end()
#define sc                     scanf
#define pf                     printf
#define SORT( V )              sort( V.begin(), V.end() )
#define clr( V )               V.clear( )
#define sz( V )                (int)V.size( )
#define REV( V )               reverse( V.begin(), V.end() )
#define MEM( a, x )            memset( a, x, sizeof( a ) )
#define mp                     make_pair
#define pp                     pop_back
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


vector < int > V;
unordered_map < int  , int > M;

int L[ N ] , R[ N ] , A[ N ] , B[ N ];
int cum[ N ];


const int sz = N;

struct SegmentTree {

    int Tree[ 4*sz ];

    inline void Init( ) {
        memset( Tree , 0 , sizeof( Tree ) );
    }
    inline void Build( int node , int b , int e ) {
        if( b > e ) return;
        if( b == e ) { Tree[ node ] = cum[ b ]; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Build( left , b , mid );
        Build( right , mid+1 , e );
        Tree[ node ] = max( Tree[ left ] , Tree[ right ] );
    }
    inline void Update( int node , int b , int e , int pos , int val ) {
        if( pos > e || pos < b || b > e ) return;
        if( b == e && b == pos ) { Tree[ node ] = val; return; }
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        Update( left , b , mid , pos , val );
        Update( right , mid+1 , e , pos , val );
        Tree[ node ] = max ( Tree[ left ] , Tree[ right ] );
    }
    inline int Query( int node , int b , int e , int i , int j ) {
        if( i > e || j < b || b > e ) return -inf;
        if( i <= b && j >= e ) return Tree[ node ];
        int left = node << 1 , right = left | 1 , mid = ( b+e ) >> 1;
        int Q1 = Query( left , b , mid , i , j );
        int Q2 = Query( right , mid+1 , e , i , j );
        return max( Q1 , Q2 );
    }

} segtree;

int main( int argc , char const *argv[] ) {

    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d %d",&L[i],&R[i]);
        V.pb( L[i] ) , V.pb( R[i] );
    }
    int q;
    scanf("%d",&q);
    for( int i = 1; i <= q; i++ ) {
        scanf("%d %d",&A[i],&B[i]);
        V.pb( A[i] ) , V.pb( B[i] );
    }
    Unique( V );
    int id = 0;
    for( int i = 0; i < V.size(); i++ ) {
        if( M[ V[i] ] == 0 ) M[ V[i] ] = ++id;
    }
    for( int i = 1; i <= n; i++ ) {
        int x = M[ L[i] ];
        int y = M[ R[i] ];
        cum[ x ]++ , cum[ y+1 ]--;
    }
    for( int i = 1; i <= id; i++ ) cum[i] += cum[i-1];
    segtree.Init( );
    segtree.Build( 1 , 1 , id );
    for( int i = 1; i <= q; i++ ) {
        int l = M[ A[i] ];
        int r = M[ B[i] ];
        int ans = segtree.Query( 1 , 1 , id , l , r );
        printf("%d\n",ans);
    }
    return 0;
}


