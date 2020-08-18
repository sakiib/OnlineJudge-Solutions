#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
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

int n;
LL x , y;
string s;
int one , zero;

int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n >> x >> y;
        cin >> s;
        for( int i = 0; i < s.size(); i++ ) {
                if( s[i] == '1' ) one++;
                else zero++;
        }
        if( zero == 0 ) return cout << 0 << endl,0;
        if( one == 0 ) return cout << y << endl,0;
        LL op1 = 0;
        one = 0 , zero = 0;
        for( int i = 0; i < sz(s); i++ ) {
                    if( s[i] == '1' ) op1 += ( y*(zero > 0 ) ) , zero = 0;
                    else zero++;
        }
        op1 += ( y*(zero>0) );
        for( int i = 0; i < sz(s); ) {
                if( s[i] == '1' ) {
                        one++;
                        while( s[i] == '1' && i < sz(s) ) i++;
                }
                else i++;
        }
        cout << min( op1 , one*x+y ) << endl;
        return 0;
}






