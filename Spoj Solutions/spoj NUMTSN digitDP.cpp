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

string L , R;
int Num[ 60 ];
int len;
LL dp[ 55 ][ 3 ][ 20 ][ 20 ][ 20 ];

void calc( string str ) {
    mem( Num , 0 );
    len = str.size( );
    FOR( i , 0 , len ) Num[i] = ( str[i]-'0' );
}
LL go( int pos , int chk , int c3 , int c6 , int c9 ) {
    //debug( c3 , c6 , c9 );
    if( c3 > 18 || c6 > 18 || c9 > 18 ) return 0;
    if( pos >= len ) return ( c3 == c6 && c6 == c9 && c3 > 0 );
    if( dp[pos][chk][c3][c6][c9] != -1 ) return dp[pos][chk][c3][c6][c9];
    LL ret = 0;
    if( chk ) {
        FOR( dgt , 0 , 9 ) {
            if( dgt == 3 ) ret += go( pos+1 , 1 , c3+1 , c6 , c9 );
            else if( dgt == 6 ) ret += go( pos+1 , 1 , c3 , c6+1 , c9 );
            else if( dgt == 9 ) ret += go( pos+1 , 1 , c3 , c6 , c9+1 );
            else ret += go( pos+1 , 1 , c3 , c6 , c9 );
        }
    }
    else {
        FOR( dgt , 0 , Num[pos]-1 ) {
            if( dgt == 3 ) ret += go( pos+1 , 1 , c3+1 , c6 , c9 );
            else if( dgt == 6 ) ret += go( pos+1 , 1 , c3 , c6+1 , c9 );
            else if( dgt == 9 ) ret += go( pos+1 , 1 , c3 , c6 , c9+1 );
            else ret += go( pos+1 , 1 , c3 , c6  , c9 );
        }
        if( Num[pos] == 3 ) ret += go( pos+1 , 0 , c3+1 , c6 , c9 );
        else if( Num[pos] == 6 ) ret += go( pos+1 , 0 , c3 , c6+1 , c9 );
        else if( Num[pos] == 9 ) ret += go( pos+1 , 0 , c3 , c6 , c9+1 );
        else ret += go( pos+1 , 0 , c3 , c6 , c9+1 );
    }
    return dp[pos][chk][c3][c6][c9] = ret%mod;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    FOR( tc , 1 , t ) {
        cin >> L >> R;
        calc( R );
        mem( dp , -1 );
        LL Ans1 = go( 0 , 0 , 0 , 0 , 0 );
        //debug( Ans );
        mem( dp , -1 );
        calc( L );
        LL Ans2 = go( 0 , 0 , 0 , 0 , 0 );
        bug( Ans1 , Ans2 );
        /*
        Ans %= mod;
        int th = 0 , sx = 0 , ni = 0;
        FOR( i , 0 , sz(L) ) {
            if( L[i] == '3' ) th++;
            if( L[i] == '6' ) sx++;
            if( L[i] == '9' ) ni++;
        }
        if( th == sx && sx == ni && th > 0 ) Ans++;
        Ans %= mod;
        cout << Ans << endl;
        */
    }
    return 0;
}









