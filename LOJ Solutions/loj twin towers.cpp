/**
 * Created by Sakib on 06/16/2018.
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

vector < int > x;
vector < string > y;
string ans[ N ];

int main( int argc, char const *argv[] ) {
    fast_io;
    bool f = false;
    int t;
    cin >> t;
    cin.ignore();
    while( t-- ) {
        x.clear() , y.clear();
        string blank;
        getline( cin , blank );
        if( f ) cout << endl;
        f = true;
        int cnt = 0;
        string a;
        getline( cin , a );
        stringstream iss( a );
        int num;
        while( iss >> num ) x.pb( num ) , cnt++;
        string b;
        getline( cin , b );
        stringstream is( b );
        string n;
        while( is >> n ) y.pb( n );
        //cout << "cnt : " << cnt << endl;
        //for( auto i : x ) cout << i << " ";
        //cout << endl;
        //for( auto i : y ) cout << i << " ";
        //cout << endl;
        for( int i = 0; i < sz(x); i++ ) ans[ x[i]-1 ] = y[i];
        for( int i = 0; i < sz(y); i++ ) cout << ans[i] <<endl;
    }
    return 0;
}






