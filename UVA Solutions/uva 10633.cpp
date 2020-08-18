/**
 * Created by Sakib on 06/06/2018.
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
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );


LL bs_small( LL d ) {
    LL lo = 10 , hi = INF , ret = -1;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        LL val = mid-mid/10;
        if( val == d ) {
            ret = mid;
            hi = mid-1;
        }
        else if( val < d ) lo = mid+1;
        else if( val > d ) hi = mid-1;
    }
    return ret;
}
LL bs_big( LL d ) {
    LL lo = 10 , hi = INF , ret = -1;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        LL val = mid-mid/10;
        if( val == d ) {
            ret = mid;
            lo = mid+1;
        }
        else if( val < d ) lo = mid+1;
        else if( val > d ) hi = mid-1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    fast_io;
    LL d;
    while( cin >> d ) {
        if( d == 0 ) break;
        LL mn = bs_small( d );
        LL mx = bs_big( d );
        //bug( mn , mx );
        for( LL i = mn; i <= mx; i++ ) {
            if( i == mn ) cout << i;
            else cout << " " << i;
        }
        cout << endl;
    }
    return 0;
}









