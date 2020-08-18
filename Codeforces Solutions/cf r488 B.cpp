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

struct data {
    LL x , y;
    int id;
    data(){}
    data( LL x , LL y , int id ) : x(x),y(y),id(id){}
    bool operator <( const data &q ) const {
        return ( x < q.x );
    }
};

int n , k;
data a[ N ];
priority_queue < LL > Q;
LL add[ N ];

int main( int argc, char const *argv[] ) {
    fast_io;
    cin >> n >> k;
    FOR( i , 1 , n ) cin >> a[i].x , a[i].id = i;
    FOR( i , 1 , n ) cin >> a[i].y;
    sort( a+1 , a+n+1 );
    //FOR( i , 1 , n ) cout << a[i].x << " " << a[i].y << " " << a[i].id << endl;
    for( int i = 1; i <= n; i++ ) {
        if( i == 1 ) {
            Q.push( a[i].y );
            continue;
        }
        int rem = k;
        queue < LL > spare;
        for( int j = i-1; j >= 1 && rem > 0; j-- , rem-- ) {
            if( !Q.empty() ) add[ a[i].id ] += Q.top() , spare.push( Q.top() ) , Q.pop();
        }
        Q.push( a[i].y );
        while( !spare.empty() ) Q.push( spare.front() ) , spare.pop();
    }
    FOR( i , 1 , n ) cout << a[ a[i].id ].y+add[i] << " ";
    return 0;
}






