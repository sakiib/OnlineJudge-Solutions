/**
 * Created by Sakib on 06/05/2018.
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

LL L , R;
vector <int> Num;
int len;
int mx;
LL dp[ 18 ][ 3 ][ 150 ];

void calc( LL n ) {
    Num.clear();
    while( n ) Num.push_back( n%10 ) , n /= 10;
    len = Num.size();
    reverse( Num.begin() , Num.end() );
}
LL go( int pos , int chk , LL tot ) {
    if( pos >= len ) return tot;
    LL ret = 0;
    if( dp[pos][chk][tot] != -1 ) return dp[pos][chk][tot];
    if( chk ) {
        for( int dgt = 0; dgt <= 9; dgt++ ) {
            ret += go( pos+1 , 1 , tot+dgt );
        }
    }
    else {
        for( int dgt = 0; dgt < Num[pos]; dgt++ ) {
            ret += go( pos+1 , 1 , tot+dgt );
        }
        ret += go( pos+1 , 0 , tot+Num[pos] );
    }
    return dp[pos][chk][tot] = ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    while( t-- ) {
        memset( dp , -1 , sizeof(dp) );
        cin >> L >> R;
        if( L > R ) swap( L  , R );
        LL ans = 0;
        if( R <= 0 ) ans = 0;
        else calc( R ) , ans = go( 0 , 0 , 0 );
        memset( dp , -1 , sizeof(dp) );
        L--;
        if( L <= 0 ) ans -= 0;
        else calc( L ) , ans -= go( 0 , 0 , 0 );
        cout << ans << endl;
    }
    return 0;
}










