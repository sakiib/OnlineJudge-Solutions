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

int a[ 500 ];
vector < int > V;

int main( int argc, char const *argv[] ) {
        fast_io;
        int n;
        cin >> n;
        for( int i = 1; i <= 2*n; i++ ) cin >> a[i] , V.pb( a[i] );
        while( sz(V) && V[0] == V[1] ) {
                V.erase( V.begin() , V.begin()+2 );
        }
        while( sz(V) && ( V[ sz(V)-1 ] == V[ sz(V)-2] ) ) {
                V.erase( V.begin()+sz(V)-2 , V.begin()+sz(V) );
        }
        if( sz(V) == 0 ) return cout << 0 << endl,0;
        int ans = 0;
        while( 1 ) {
                int x = V[0];
                for( int i = 1; i < V.size(); i++ ) {
                     if( V[i] == x ) {
                            int j = i;
                            while( V[j-1] != x ) swap( V[j] , V[j-1] ) , ans++;
                            break;
                     }
                }
                while( sz(V) && V[0] == V[1] ) {
                        V.erase( V.begin() , V.begin()+2 );
                }
                while( sz(V) && ( V[ sz(V)-1 ] == V[ sz(V)-2] ) ) {
                        V.erase( V.begin()+sz(V)-2 , V.begin()+sz(V) );
                }
                if( sz(V) == 0 ) break;
        }
        cout << ans << endl;
        return 0;
}






