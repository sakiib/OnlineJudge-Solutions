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

string s;
int len;
LL dp[ 5005 ];

LL solve( int pos ) {
    if( pos >= len ) return 1;
    LL ret = 0;
    if( dp[pos] != -1 ) return dp[pos];
    if( s[pos] == '0' ) return 0;
    ret += solve( pos+1 );
    if( pos+1 <= len-1 ) {
        int num = ( s[pos]-'0' )*10+( s[pos+1]-'0' );
        if( num >= 1 && num <= 26 ) ret += solve( pos+2 );
    }
    return dp[pos] = ( ret );
}
int main( int argc, char const *argv[] ) {
    fast_io;
    while( cin >> s ) {
        if( s == "0" ) break;
        len = sz(s);
        mem( dp , -1 );
        cout << solve( 0 ) << endl;
    }
    return 0;
}
