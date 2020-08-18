/**
 * Created by Sakib on 06/12/2018.
 */
#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
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

int Set( int N , int pos )    { return N = N | ( 1 << pos ); }
int Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos ) { return (bool)( N & ( 1 << pos ) ); }

int ara[ 16 ][ 16 ];
int n;
LL dp[ 16 ][ 1 << 16 ];

LL go( int pos , int mask ) {
    if( mask == ( 1 << n )-1 ) return 0;
    if( dp[pos][mask] != -1 ) return dp[pos][mask];
    LL ret = 0;
    FOR( i , 0 , n-1 ) {
        if( !Check( mask , i ) ) {
           ret = max( ret , go( pos+1 , Set( mask , i ) )+ara[pos][i] );
        }
    }
    return dp[pos][mask] = ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    FOR( tc , 1 , t ) {
        scanf("%d",&n);
        FOR( i , 0 , n-1 ) {
            FOR( j , 0 , n-1 ) {
                scanf("%d",&ara[i][j]);
            }
        }
        mem( dp , -1 );
        printf("Case %d: %lld\n",tc,go( 0 , 0 ));
    }
    return 0;
}









