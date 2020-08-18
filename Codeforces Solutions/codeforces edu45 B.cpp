/**
 * Created by Sakib on 06/10/2018.
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

int n , k;
vector <LL> V;
multiset <LL> S;
LL val;

bool ok( LL val ) {
    int lo = 0 , hi = sz(V)-1 , ret = -1;
    while( lo <= hi ) {
        int mid = (lo+hi)/2;
        if( V[mid] <= val ) lo = mid+1;
        else ret = mid , hi = mid-1;
    }
    bug( "here" , ret );
    if( ret != -1 ) return true;
    return false;
}
bool yes( int s , LL val ) {
    int lo = s , hi = sz(V)-1 , ret = -1;
    while( lo <= hi ) {
        int mid = (lo+hi)/2;
        if( V[mid] > val ) hi = mid-1;
        else ret = mid , lo = mid+1;
    }
    bug( "Nhere" , ret );
    if( ret != -1 ) return true;
    return false;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n >> k;
    FOR( i , 1 , n ) cin >> val , S.insert( val ) , V.pb( val );
    Unique( V );
    int ans = n;
    int s = 1;
    for( auto x : S ) {
        if( ok( x ) && yes( s , x+k ) ) ans--;
        else cout << x << endl;
        s++;
        cout << "*******" << endl;
    }
    cout << ans << endl;
    return 0;
}










