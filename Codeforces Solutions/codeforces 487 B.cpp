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

bool can[ N ];

int main( int argc, char const *argv[] ) {
    fast_io;
    int n , p;
    cin >> n >> p;
    string s;
    cin >> s;
    s = 'x'+s;
    for( int i = 1; i+p < sz(s); i++ ) {
        if( s[i] == '1' && s[i+p] == '.' ) s[i+p] = '0';
        else if( s[i] == '0' && s[i+p] == '.' ) s[i+p] = '1';
    }
    for( int i = sz(s)-1; i-p >= 1; i-- ) {
        if( s[i] == '1' && s[i-p] == '.' ) s[i-p] = '0';
        else if( s[i] == '0' && s[i-p] == '.' ) s[i-p] = '1';
    }
    for( int i = 1; i < sz(s); i++ ) {
        if( s[i] != '.' ) continue;
        if( i < sz(s)/2 ) s[i] = '0';
        else s[i] = '1';
    }
    for( int i = 1; i+p < sz(s); i++ ) {
        if( s[i] != s[i+p]  ) return cout << s.substr( 1 , sz(s)-1 ) << endl,0;
    }

    for( int i = sz(s)-1; i-p >= 1; i-- ) {
        if( s[i] != s[i-p]  ) return cout << s.substr( 1 , sz(s)-1 ) << endl,0;
    }
    cout << "No" << endl;
    return 0;
}









