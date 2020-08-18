/**
 * Created by Sakib on 06/13/2018.
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

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

int n , k;
int a[ 20 ];
int dp[ 18 ][ 1 << 18 ];

bool ok( int pos , int mask ) {

    bool ret = false;
    FOR( i , 0 , n-1 ) {
        if( Check( mask , i ) ) continue;
        if( )
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    FOR( tc , 1 , t ) {
        scanf("%d %d",&n,&k);
        FOR( i , 0 , n-1 ) scanf("%d",&a[i]);
        mem( dp , -1 );
        if( ok( 0 , 0 ) ) printf("Case %d: Yes\n",tc);
        else printf("Case %d: No\n",tc);
    }
    return 0;
}









