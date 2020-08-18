/**
 * Created by Sakib on 06/16/2018.
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

vector < ii > a , b;
int n , m;
vector < ii > p , q;
bool badA[ 20 ] , badB[ 20 ];

set < int > S;

void go( int id ) {
    for( int i = 0; i < sz(q); i++ ) {
        if( p[id].first == q[i].first || p[id].first == q[i].second ) S.insert( p[id].first );
        if( p[id].second == q[i].second || p[id].second == q[i].first ) S.insert( p[id].second );
    }
}
int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n >> m;
    int x , y;
    FOR( i , 1 , n ) cin >> x >> y , a.pb( mp(x,y) );
    FOR( i , 1 , m ) cin >> x >> y , b.pb( mp(x,y) );
    FOR( i , 0 , sz(a)-1 ) {
        FOR( j , 0 , sz(b)-1 ) {
            if( (a[i].first == b[j].first) && (a[i].second == b[j].second) ) {
                badA[i] = true;
                badB[j] = true;
            }
        }
    }
    for( int i = 0; i < sz(a); i++) if( !badA[i] ) p.pb( mp(a[i].first,a[i].second) );
    for( int i = 0; i < sz(b); i++ ) if( !badB[i] ) q.pb( mp(b[i].first,b[i].second) );

    //for( auto x : p ) cout << x.first << " " << x.second << endl;
    //cout << endl;
    //for( auto x : q ) cout << x.first << " " << x.second << endl;
    //cout << endl;
    for( int i = 0; i < sz(p); i++ ) if( p[i].first > p[i].second ) swap( p[i].first , p[i].second );
    for( int i = 0; i < sz(q); i++ ) if( q[i].first > q[i].second ) swap( q[i].first , q[i].second );
    for( int i = 0; i < sz(p); i++ ) {
        go( i );
    }
    if( sz(S) == 0 ) return cout << -1 <<endl,0;
    if( sz(S) >= 2 ) return cout << 0 << endl,0;
    for( auto x : S ) cout << x << endl;
    return 0;
}






