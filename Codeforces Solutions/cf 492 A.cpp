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

vector < int> V = { 1 , 5 , 10 , 20 , 100 };
int one , ten , f , twen , hun;

int main( int argc, char const *argv[] ) {
        fast_io;
        LL n;
        cin >> n;
        while( n ) {
            if( n >= 100 ) {
                while( n >= 100 ) n -= 100 , hun++;
            }
            if( n >= 20 ) {
                while( n >= 20 ) n -= 20 , twen++;
            }
            if( n >= 10 ) {
                while( n >= 10 ) n -= 10 , ten++;
            }
            if( n >= 5 ) {
                while( n >= 5 ) n -= 5 , f++;
            }
            if( n >= 1 ) {
                while( n >= 1 ) n-- , one++;
            }
        }
        if( one >= 5 ) f += one/5 , one %= 5;
        if( f >= 2 ) ten += f/2 , f %= 5;
        if( ten >= 2 ) twen += ten/2 , twen %= 2;
        if( twen >= 5 ) hun += twen/5 , twen %= 5;
        cout << one+f+ten+twen+hun << endl;
        return 0;
}






