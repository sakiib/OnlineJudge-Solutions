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
int w[ N ] , h[ N ];

int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                cin >> w[i] >> h[i];
        }
        if( n == 1 ) return cout << "YES" << endl,0;
        for( int i = 1; i <= n; i++ ) {
                if( i == 1 ) {
                        if( w[i] > h[i] ) swap( w[i] , h[i] );
                }
                else {
                        int op1 = w[i] , op2 = h[i];
                        if( op1 > op2 ) swap( op1 , op2 );
                        if( op2 <= h[i-1] ) h[i] = op2;
                        else if( op1 <= h[i-1] ) h[i] = op1;
                        else return cout << "NO" << endl,0;
                }
        }
        cout << "YES" << endl;
        return 0;
}






