/**
 * Created by Sakib on 06/11/2018.
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

int val;
int coin [] = { 2000, 1000, 400, 200, 100 , 40, 20, 10, 4, 2 ,1 };
int dp[ 15 ][ 6500 ];

int go( int pos , int rem ) {
    if( pos >= 11 ) return ( rem == 0 );
    if( rem < 0 ) return 0;
    if( rem == 0 ) return 1;
    if( dp[pos][rem] != -1 ) return dp[pos][rem];
    int op1 = 0 , op2 = 0;
    op1 += go( pos+1 , rem );
    op2 += go( pos , rem-coin[pos] );
    return dp[pos][rem] = op1+op2;
}
int main( int argc, char const *argv[] ) {
    //fast_io;
    double tot;
    mem( dp , -1 );
    //go( 0 , 6000 );
    while( cin >> tot ) {
        val = tot*20;
        if( val == 0 ) break;
        //bug( val , dp[0][val] );
        printf("%6.2lf%17d\n",tot,go( 0 , val ));
    }
    return 0;
}
