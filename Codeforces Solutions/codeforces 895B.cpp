/**
 * Created by Sakib on 06/14/2018.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
template <typename T>
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
struct debugger{
template<typename T>debugger& operator,(const T& v){cerr<<v<<" ";return *this;}}dbg;

#define Fix( x ) setprecision( x ) << fixed
#define mem( a , x ) memset( a , x , sizeof( a ) )
#define bug( a , b ) cerr<< #a <<" = "<<a<<" , "<< #b <<" = "<<b<<"\n";
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define FOR( i , a , b ) for( int i = a; i <= b; i++ )
#define ROF( i , a , b ) for( int i = a; i >= b; i-- )
#define sz( V ) (int)V.size( )
#define all( V ) V.begin( ),V.end( )
#define Found( S , val ) S.find( val ) != S.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )
typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

LL n;
LL dp[ 19 ][ 2 ][ 10 ][ 1111 ];
vector <int> Num;
int len;

void calc( LL n ) {
    Num.clear();
    while( n ) Num.pb( n%10 ) , n /= 10;
    reverse( all(Num) );
    len = sz(Num);
}
void cal( ) {
    FOR( i , 1 , len-1 ) Num.pb( 0 );
}
LL go( int pos , int chk , int mx , int mask ) {
    debug( pos , chk , mx , mask );
    if( pos >= len ) return ( __builtin_popcount(mask) == mx );
    if( dp[pos][chk][mx][mask] != -1 ) return dp[pos][chk][mx][mask];
    LL ret = 0;
    if( chk ) FOR( i , 0 , 9 ) ret += go( pos+1 , 1 , max( mx , i ) , Set( mask , i ) );
    else {
        FOR( i , 0 , Num[pos]-1 ) ret += go( pos+1 , 1 , max( mx , i ) , Set( mask , i ) );
        ret += go( pos+1 , 0 , max( mx , Num[pos] ) , Set( mask , Num[pos] ) );
    }
    return dp[pos][chk][mx][mask] = ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    while( t-- ) {
        cin >> n;
        calc( n );
        mem( dp , -1 );
        LL ans = go( 0 , 0 , 0 , 0 );
        cal( );
        mem( dp , -1 );
        ans -= go( 0 , 0 , 0 , 0 );
        cout << ans << endl;
    }
    return 0;
}





