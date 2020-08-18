/**
 * Created by Sakib on 06/08/2018.
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

int n;
LL a[ 10*N ];
LL L[ 10*N ] , R[ 10*N ];
map <LL,int> M;
vector <LL> V;
LL ans;

struct BinaryIndexedTree {

    int BIT[ 10*N+10 ];

    inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

    inline int RQuery ( int l , int r ) { return PQuery( r ) - PQuery( l-1 ); }

    inline void PUpdate ( int idx , int val ) {
        for( ; idx <= 10*N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
    }
    inline int PQuery ( int idx ) {
        int ret = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ]; return ret;
    }
    inline void RUpdate ( int idx , int idy , int val ) {
        for( ; idx <= 10*N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
        idy++ , val *= -1;
        for( ; idy <= 10*N; idy += ( idy & -idy ) ) BIT[ idy ] += val;
    }
} bit;

void compress( ) {
    int id = 0;
    Unique( V );
    FOR( i , 0 , sz(V)-1 ) M[V[i]] = ++id;
    FOR( i , 1 , n ) a[i] = M[a[i]];
}
int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n;
    FOR( i , 1 , n ) cin >> a[i] , V.pb( a[i] );
    compress( );
    FOR( i , 1 , n ) L[i] = bit.RQuery( a[i]+1 , 10*N ) , bit.PUpdate( a[i] , +1 );
    bit.Init();
    ROF( i , n , 1 ) R[i] = bit.RQuery( 1 , a[i]-1 ) , bit.PUpdate( a[i] , +1 );
    FOR( i , 2 , n-1 ) ans += ( L[i]*R[i] );
    cout << ans << endl;
    return 0;
}









