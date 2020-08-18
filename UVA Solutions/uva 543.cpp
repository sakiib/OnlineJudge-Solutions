/**
 * Created by Sakib on 06/04/2018.
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

vector < pair<string,int> > V;

int main( int argc, char const *argv[] ) {
    fast_io;
    string s;
    cin >> s;
    s += 'a';
    s += 'b';
    int i = 0 , j = 0;
    string str = "";
    int cnt = 0;
    while( i <= j && j < sz(s) ) {
        if( s[i] == s[j] ) {
           cnt++;
           str = s[i];
           j++;
        }
        else {
            V.pb( mp(str,cnt) );
            cnt = 0;
            str = str[j];
            i = j;
        }
    }
    for( auto x : V ) cout << x.first << x.second;
    cout << endl;
    return 0;
}








