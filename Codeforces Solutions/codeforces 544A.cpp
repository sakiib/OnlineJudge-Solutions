/**
 * Created by Sakib on 06/15/2018.
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
int n;
int a[ 105 ];
int mn_amount;
int dp[ 105 ][ 10005 ];

int solve( int pos , int taken ) {
    if( pos > n ) return ( taken == mn_amount ? 0 : inf );
    if( taken == mn_amount ) return 0;
    if( taken > mn_amount ) return inf;
    if( dp[pos][taken] != -1 ) return dp[pos][taken];
    int op1 = inf , op2 = inf;
    op1 = min( op1 , solve( pos+1 , taken+a[pos] )+1 );
    op2 = min( op2 , solve( pos+1 , taken ) );
    return dp[pos][taken] = min( op1 , op2 );
}
int go( int pos , int taken ) {
    if( pos > n ) return ( taken >= tot ? 0 : inf );
    if( taken >= tot ) return 0;
    if( dp[pos][taken] != -1 ) return dp[pos][taken];
    int op1 = inf , op2 = inf;
    op1 = min( op1 , go( pos+1 , taken+a[pos] )+a[pos] );
    op2 = min( op2 , go( pos+1 , taken ) );
    return dp[pos][taken] = min( op1 , op2 );
}
int main( int argc, char const *argv[] ) {
    //fast_io;
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%d",&tot);
        scanf("%d",&n);
        FOR( i , 1 , n ) scanf("%d",&a[i]);
        mem( dp , -1 );
        mn_amount = go( 1 , 0 );
        printf("%d ",mn_amount);
        mem( dp , -1 );
        printf("%d\n",solve( 1 , 0 ) );
    }
    return 0;
}





