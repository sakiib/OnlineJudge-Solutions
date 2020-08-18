/**
 * Created by Sakib on 06/18/2018.
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

LL cnt = 0;

template < typename T > inline T GCD( T a , T b ) { a = abs(a) , b = abs(b); return !b ? a : GCD(b, a % b); }
template < typename T > inline T LCM( T x , T y ) { T g = GCD( x , y ); return x*y/g; }

vector < LL > V;

int main( int argc, char const *argv[] ) {
    fast_io;
    LL l , r , x , y;
    cin >> l >> r >> x >> y;
    LL sq = sqrt( y );
    for( LL i = 1; i <= sq; i++ ) {
        if( y%i == 0 ) {
            V.pb( i );
            if( y/i != i ) V.pb( y/i );
        }
    }
    for( int i = 0; i < sz(V); i++ ) {
        for( int j = 0; j < sz(V); j++ ) {
            if( V[i] < l || V[j] < l || V[i] > r || V[j] > r ) continue;
            LL g = GCD( V[i] , V[j] );
            LL lc = (V[i]*V[j])/g;
            if( g == x && lc == y ) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
