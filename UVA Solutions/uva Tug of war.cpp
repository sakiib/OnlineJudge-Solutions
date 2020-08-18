/**
 * Created by Sakib on 06/15/2018.
 */
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(args...) { dbg,args; cerr<<"\n"; }
template <typename T>
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
int tot;
int a[ N ];
int dp[ 105 ][ 55 ];
int ret = inf;

int solve( int pos , int groupA ) {
    if( pos > n ) {
        int A = groupA , B = n-groupA;
        if( abs( A-B ) <= 1 ) return 0;
        else return inf;
    }
    int op1 = inf , op2 = inf ;
    op1 = min( op1 , solve( pos+1 , groupA+1 )+a[pos] );
    op2 = min( op2 , solve( pos+1 , groupA ) );
    int k = min( op1 , op2 );
    int an = tot-k;
    bug( k , an );
    return k;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    int t;
    cin >> t;
    while( t-- ) {
        tot = 0;
        cin >> n;
        mem( dp , -1 );
        FOR( i , 1 , n ) cin >> a[i] , tot += a[i];
        int ans = solve( 1 , 0 );
        cout <<"ans : "<< ans << endl;
    }
    return 0;
}






