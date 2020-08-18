/**
 * Created by Sakib on 6/01/2018.
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

const int base = 31;

int len , q;
string str;
LL power[ N ];

void gen_pow( ) {
    power[0] = 1LL;
    FOR( i , 1 , N-1 ) power[i] = power[i-1] * base;
}
pair <LL,LL> get_hash( string str ) {
    LL f = 0 , b = 0;
    FOR( i , 0 , sz(str)-1 ) f += ( power[i] * str[i] );
    int k = 0;
    ROF( i , sz(str)-1 , 0 ) b += ( power[i] * str[k++] );
    return mp(f,b);
}
pair <LL,LL> update_hash( pair<LL,LL> Hash , int pos , string s ) {
    LL f = Hash.first;
    LL b = Hash.second;
    char ch = s[0];
    --pos;
    f -= ( str[pos] * power[pos] );
    f += ( ch * power[pos] );
    b -= ( str[pos] * power[len-1-pos] );
    b += ( ch * power[len-pos-1] );
    str[pos] = ch;
    return mp(f,b);
}
int main( int argc, char const *argv[] ) {
    fast_io;
    gen_pow( );
    int t;
    cin >> t;
    while( t-- ) {
        cin >> len >> q;
        cin >> str;
        pair <LL,LL> Hash = get_hash( str );
        int ans = 0;
        while( q-- ) {
            int pos;
            string s;
            cin >> pos >> s;
            pair <LL,LL> cur = update_hash( Hash , pos , s );
            // bug( cur.first , cur.second );
            Hash = cur;
            if( cur.first == cur.second ) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
