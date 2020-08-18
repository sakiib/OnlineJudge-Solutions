/**
 * Created by Sakib on 06/09/2018.
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

string s;
int m;
int len;
int dp[ 1 << 10 ][ 10005 ];
LL fact[ 15 ];
int cnt[ 15 ];

void calc( ) {
    fact[0] = 1;
    for( int i = 1; i <= 10; i++ ) fact[i] = fact[i-1]*i;
}
int go( int mask , int rem ) {
    if( mask == ( 1 << len )-1 ) return rem == 0;
    if( dp[mask][rem] != -1 ) return dp[mask][rem];
    int ret = 0;
    FOR( i , 0 , len-1 ) {
        if( !Check( mask , i ) ) ret += go( Set(mask,i) , (rem*10+s[i]-'0')%m );
    }
    return dp[mask][rem] = ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    calc( );
    int t;
    cin >> t;
    while( t-- ) {
        cin >> s >> m;
        len = s.size();
        mem( dp , -1 );
        int tot = 0;
        tot = go( 0 , 0 );
        memset( cnt , 0 , sizeof(cnt) );
        for( int i = 0; i < len; i++ ) cnt[ s[i]-'0' ]++;
        for( int i = 0; i <= 9; i++ ) tot /= fact[ cnt[i] ];
        cout << tot << endl;
    }
    return 0;
}









