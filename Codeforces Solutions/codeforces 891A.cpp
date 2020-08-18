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
const int N = 2005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n;
int ara[ N ];
int Table[ N ][ 15 ];
int lg[ N ];


void Build_Table( ) {
    for( int i = 1; i <= N; i++ ) Table[i][0] = ara[i];
    for( int i = 2; i <= N; i++ ) lg[i] = lg[i/2] + 1;
    for( int j = 1; ( 1 << j ) <= N; j++ ) {
        for( int i = 1; i+( 1 << j )-1 <= N; i++ ) {
            Table[i][j] = __gcd( Table[i][j-1] , Table[i+(1<<(j-1))][j-1] );
        }
    }
}
int Query( int l , int r ) {
    if( l > r ) swap( l , r );
    int k = lg[r-l+1];
    return __gcd( Table[l][k] , Table[r-(1<<k)+1][k] );
}
int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n;
    int cnt = 0;
    FOR( i , 1 , n ) cin >> ara[i] , ( ara[i] == 1 ? cnt = cnt+1 : cnt = cnt );
    Build_Table( );
    if( cnt > 0 ) return cout << n-cnt << endl,0;
    int len = 2*inf;
    for( int i = 1; i <= n; i++ ) {
        int lo = i , hi = n , res = 2*inf;
        while( lo <= hi ) {
            int mid = ( lo+hi ) >> 1;
            if( Query( i , mid ) != 1 ) {
                lo = mid+1;
            }
            else {
                res = mid;
                hi = mid-1;
            }
        }
        if( res != 2*inf ) len = min( len , res-i+1 );
    }
    if( len == 2*inf ) cout << -1 << endl;
    else cout << len-1+( n-1 ) << endl;
    return 0;
}









