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

bool vowel( char ch ) {
        return ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );
}
bool con( char ch ) {
        if( !vowel( ch ) ) return true;
        return false;
}
int main( int argc, char const *argv[] ) {
        fast_io;
        string s;
        cin >> s;
        int len = s.size();
        if( con( s[len-1] ) && s[len-1] != 'n' ) return cout << "NO" << endl,0;
        for( int i = 0; i < len-1; i++ ) {
                if( s[i] == 'n' ) continue;
                if( con( s[i] ) && con( s[i+1] ) ) return cout << "NO" << endl,0;
        }
        return cout << "YES" << endl,0;
        return 0;
}






