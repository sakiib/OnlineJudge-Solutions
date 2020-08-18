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

int tot;
int a[ 105 ];
int n;
int half;
int dp[ 105 ][ 105 ];
bool dir[ 105 ][ 5000 ];

int solve( int pos , int pep ) {
    if( pos > n || pep > n ) return( ( abs(pep-(n-pep)) <= 1 ) ? 0 : inf );
    //if( taken >= half ) return ( ( abs(pep-(n-pep)) <= 1 ) ? 0 : inf );
    if( dp[pos][pep] != -1 ) return dp[pos][pep];
    int op1 = inf , op2 = inf;
    op1 = min( op1 , solve( pos+1 ,  pep+1 )+a[pos] );
    op2 = min( op2 , solve( pos+1 , pep ) );
    //dir[pos][taken] = ( op1 < op2 );
    bug( op1 , op2 );
    if( op1 >= half && op1 < inf ) dp[pos][pep] = op1;
    if( op2 >= half && op2 < inf ) dp[pos][pep] = op2;
    return dp[pos][pep];
}
void path( int pos , int rem ) {
    vector < int > mark;
    int j = rem;
    FOR( i , 1 , n ) {
        if( dir[i][j] ) {
            j += ( a[i] );
            mark.pb( i );
        }
    }
    cout <<"sz : "<< sz( mark ) << endl;
    for( auto x : mark ) cout << a[x] << endl;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    bool f = false;
    int t;
    cin >> t;
    while( t-- ) {
        if( f ) cout << endl;
        f = true;
        cin >> n;
        tot = 0 , half = 0;
        FOR( i , 1 , n ) cin >> a[i] , tot += a[i];
        half = tot/2;
        //bug( tot , half );
        mem( dp , -1 );
        //mem( dir , false );
        int x = solve( 1 , 0 );
        //path( 1 , 0 );
        //cout << "x : " << x << endl;
        int y = tot-x;
        cout << min( x , y ) << " " << max( x , y ) << endl;
    }
    return 0;
}

/**
8
4
97
50
11
96
45
27
52
*/





