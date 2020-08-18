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



LL n , q;
LL ara[ N ];

unordered_map < int , bool > BAD;

struct segment { LL val , idx; } Tree[ 4*N ];

void Build( int node , int b , int e ) {
    if( b > e ) return;
    if( b == e ) {
        Tree[node].val = ara[b];
        Tree[node].idx = b;
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Build( left , b , mid );
    Build( right , mid+1 , e );
    if( Tree[left].val == Tree[right].val ) {
        Tree[node].val = Tree[left].val; Tree[node].idx = Tree[left].idx;
    }
    else if( Tree[left].val > Tree[right].val ) {
        Tree[node].val = Tree[left].val; Tree[node].idx = Tree[left].idx;
    }
    else {
        Tree[node].val = Tree[right].val; Tree[node].idx = Tree[right].idx;
    }
}
segment Query( int node , int b , int e , int i , int j , LL v ) {
    segment s = {-INF,-INF};
    if( b > e || i > e || j < b ) return s;
    if( b == e  ) {
        if( !BAD[Tree[node].idx]  && Tree[node].val <= v ) return Tree[node];
        else return s;
    }
    if( i <= b && j >= e  ) {
        if( !BAD[Tree[node].idx]  && Tree[node].val <= v ) return Tree[node];
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    segment q1 = Query( left , b , mid , i , j ,  v );
    segment q2 = Query( right , mid+1 , e , i , j ,  v );
    segment ans = {-INF,-INF};
    if( q1.val >= q2.val && !BAD[q1.idx] && q1.val <= v  ) {
        ans.val = max( ans.val , q1.val ); ans.idx = q1.idx;
    }
    else if( q2.val > q1.val && !BAD[q2.idx] && q2.val <= v  ){
        ans.val = max( ans.val , q2.val ); ans.idx = q2.idx;
    }
    return ans;
}
void Update( int node , int b , int e , int pos , LL v ) {
    if( pos > e || pos < b || b > e ) return;
    if( b == e && pos == b ) {
        Tree[node].val = v;
        Tree[node].idx = b;
        return;
    }
    int left = 2*node , right = 2*node+1 , mid = (b+e)/2;
    Update( left , b , mid , pos , v );
    Update( right , mid+1 , e , pos , v );
    if( Tree[left].val == Tree[right].val ) {
        Tree[node].val = Tree[left].val; Tree[node].idx = Tree[left].idx;
    }
    else if( Tree[left].val > Tree[right].val ) {
        Tree[node].val = Tree[left].val; Tree[node].idx = Tree[left].idx;
    }
    else {
        Tree[node].val = Tree[right].val; Tree[node].idx = Tree[right].idx;
    }
}
bool OK( LL x , LL y , LL z ) {
    return ( x+y > z && x+z > y && y+z > x );
}
LL P( LL x , LL y , LL z ) {
    LL ret = ( x+y+z );
    return ret;
}
int main( int argc , char const *argv[] ) {
    #ifdef Local_Test
    freopen( "Input.txt" , "r" , stdin );
    freopen( "Output.txt" , "w" , stdout );
    #endif // Local_Test

    sc("%lld %lld",&n,&q);
    FOR( i , 1 , n ) sc("%lld",&ara[i]);
    Build( 1 , 1 , n );
    while( q-- ) {
        int op; sc("%d",&op);
        clr( BAD );
        if( op == 1 ) {
            int pos;
            LL val;  sc("%d %lld",&pos,&val);
            Update( 1 , 1 , n , pos , val ); continue;
        }
        int l , r;  sc("%d %d",&l,&r);
        if( (r-l+1) < 3 ) {  pf("0\n"); continue;  }
        segment f = {-INF,-INF} , s = {-INF,-INF} , t = {-INF,-INF};
        LL last1 = 0 , last2 = 0 , bad = INF;
        bool found = false;
        while( true ) {
            if( f.val == -INF ) {
                f = Query( 1 , 1 , n , l , r ,  bad );
                if( f.val == -INF || f.val == 0 || f.val <= 0) break;
                else {
                    BAD[f.idx] = true;
                    bad = f.val;
                }
            }
            if( s.val == -INF ) {
                s = Query( 1 , 1 , n , l , r ,  bad );
                if( s.val == -INF || s.val == 0 || s.val <= 0 ) break;
                else {
                    BAD[s.idx] = true;
                    bad = s.val;
                }
            }
            if( t.val == -INF ) {
                t = Query( 1 , 1 , n , l , r , bad );
                if( t.val == -INF|| t.val == 0 || t.val <= 0 ) break;
                else {
                    BAD[t.idx] = true;
                    bad = t.val;
                }
            }
            if( s.val != -INF && f.val != -INF && t.val != -INF ) {
                if( OK( f.val , s.val , t.val ) ) {
                    LL ans = P( f.val , s.val , t.val );
                    pf("%lld\n",ans);
                    found = true; break;
                }
            }
            f = s , s = t; t = {-INF,-INF};
        }
        if( !found ) pf("0\n");
    }
    return 0;
}


