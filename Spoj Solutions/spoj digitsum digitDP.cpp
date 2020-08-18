/**
 * Created by Sakib on 06/08/2018.
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

int len;
vector <int> Num;
LL dp[ 18 ][ 2 ][ 150 ];

void calc( LL n ) {
    Num.clear();
    while( n ) Num.pb( n%10 ) , n /= 10;
    len = sz(Num);
    reverse( all(Num) );
}
LL go( int pos , int chk , int sum ) {
    if( pos >= len ) return sum;
    if( dp[pos][chk][sum] != -1 ) return dp[pos][chk][sum];
    LL ret = 0;
    if( chk ) {
        FOR( i , 0 , 9 ) ret += go( pos+1 , 1 , sum+i );
    }
    else {
        FOR( i , 0 , Num[pos]-1 ) ret += go( pos+1 , 1 , sum+i );
        ret += go( pos+1 , 0 , sum+Num[pos] );
    }
    return dp[pos][chk][sum] = ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    LL L , R;
    while( cin >> L >> R ) {
        if( L == -1 && R == -1 ) break;
        calc( R );
        mem( dp , -1 );
        LL ans = go( 0 , 0 , 0 );
        --L;
        if( L > 0 ) calc( L ) , mem( dp , -1) , ans -= go( 0 , 0 , 0 );
        cout << ans << endl;
    }
    return 0;
}









