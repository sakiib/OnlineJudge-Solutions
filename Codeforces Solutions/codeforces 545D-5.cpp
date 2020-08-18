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

int Set( int N , int pos )    { return N = N | ( 1 << pos ); }
int Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos ) { return (bool)( N & ( 1 << pos ) ); }

int tot;
int n;
int ara[ N ];
int mx;
int mask;

void go( int id , int cur_mask , int taken ) {
    if( taken > tot ) return;
    if( taken > mx ) mx = taken , mask = cur_mask;
    if( id >= n ) return;
    go( id+1 , Set( cur_mask , id ) , taken+ara[id] );
    go( id+1 , cur_mask , taken );
}
int main( int argc, char const *argv[] ) {
    fast_io;
    while( cin >> tot ) {
        cin >> n;
        FOR( i , 0 , n-1 ) cin >> ara[i];
        mx = 0 , mask = 0;
        go( 0 , 0 , 0 );
        FOR( i , 0 , n-1 ) if( ( mask >> i )&1 ) cout << ara[i] << " ";
        cout <<"sum:"<< mx << endl;
    }
    return 0;
}
