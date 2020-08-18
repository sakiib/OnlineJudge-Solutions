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

int dp[55][2][20][20][20];
vector <int> Num;
int len;

void calc( string s ) {
    Num.clear();
    FOR( i , 0 , sz(s)-1 ) Num.pb( s[i]-'0' );
    len = sz(Num);
}
LL go( int pos , int chk , int th , int sx , int ni ) {
    if( pos >= len ) return ( th == sx && sx == ni && th > 0 );
    if( th > 19 || sx > 19 || ni > 19 ) return 0;
    if( dp[pos][chk][th][sx][ni] != -1 ) return dp[pos][chk][th][sx][ni];
    LL ret = 0;
    if( chk ) {
        FOR( i , 0 , 9 ) {
            if( i == 3 ) ret = (ret + go( pos+1 , 1 , th+1 , sx , ni ))%mod;
            else if( i == 6 ) ret = (ret + go( pos+1 , 1 , th , sx+1 , ni ))%mod;
            else if( i == 9 ) ret = (ret + go( pos+1 , 1 , th , sx , ni+1 ))%mod;
            else ret = (ret + go( pos+1 , 1 , th , sx , ni ))%mod;
        }
    }
    else {
        FOR( i , 0 ,Num[pos]-1 ) {
            if( i == 3 ) ret = (ret%mod + go( pos+1 , 1 , th+1 , sx , ni ))%mod;
            else if( i == 6 ) ret = (ret + go( pos+1 , 1 , th , sx+1 , ni ))%mod;
            else if( i == 9 ) ret = (ret + go( pos+1 , 1 , th , sx , ni+1 ))%mod;
            else ret = (ret + go( pos+1 , 1 , th , sx , ni ))%mod;
        }
        if( Num[pos] == 3 ) ret = (ret + go( pos+1 , 0 , th+1 , sx , ni ))%mod;
        else if( Num[pos] == 6 ) ret = (ret + go( pos+1 , 0 , th , sx+1 , ni ))%mod;
        else if( Num[pos] == 9 ) ret = (ret + go( pos+1 , 0 , th , sx , ni+1 ))%mod;
        else ret = (ret + go( pos+1 , 0 , th , sx , ni ))%mod;
    }
    return dp[pos][chk][th][sx][ni] = ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    while( t-- ) {
        string a , b;
        cin >> a >> b;
        calc( b );
        mem( dp , -1 );
        LL ans = go( 0 , 0 , 0 , 0 , 0 );
        calc( a );
        mem( dp , -1 );
        ans -= go( 0 , 0 , 0 , 0 , 0 );
        ans = ans+mod;
        ans %= mod;
        int th = 0 , sx = 0 , ni = 0;
        FOR( i , 0 , sz(a)-1 ) {
            if( a[i] == '3' ) th++;
            if( a[i] == '6' ) sx++;
            if( a[i] == '9' ) ni++;
        }
        if( th == sx && sx == ni && th > 0 ) ans --;
        ans = ans+mod;
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}









