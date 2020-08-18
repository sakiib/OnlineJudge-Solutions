/**
 * Created by Sakib on 06/11/2018.
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

LL L , R;
vector <int> Num;
int len;
LL dp[ 20 ][ 2 ][ 20 ][ 2 ];

void calc( LL x ) {
    Num.clear();
    while( x ) Num.pb( x%10 ) , x /= 10;
    reverse( all(Num) );
    len = sz(Num);
}
LL go( int pos , int smaller , int zero , int st ) {
    if( pos >= len ) return ( st ? 0 : zero );
    if( dp[pos][smaller][zero][st] != -1 ) return dp[pos][smaller][zero][st];
    LL ret = 0;
    if( !st ) {
        if( smaller ) {
            FOR( i , 0 , 9 ) ret += go( pos+1 , 1 , (i==0?zero = zero+1:zero = zero) , 0 );
        }
        else {
            FOR( i , 0 , Num[pos]-1 ) ret += go(pos+1 , 1 , (i==0?zero = zero+1:zero = zero) , 0 );
        }
        ret += go( pos+1 , 0 , (Num[pos]==0?zero = zero+1:zero = zero) , 0 );
    }
    else {
        if( smaller ) {
            FOR( i , 1 , 9 ) ret += go( pos+1 , 1 , (i==0?zero = zero+1:zero = zero) , 0 );
        }
        else {
            FOR( i , 1 , Num[pos]-1 ) ret += go(pos+1 , 1 , (i==0?zero = zero+1:zero = zero) , 0 );
        }
        if( st && Num[pos] != 0 ) ret += go( pos+1 , 0 , (Num[pos]==0?zero = zero+1:zero = zero) , 0 );
    }
    return dp[pos][smaller][zero][st] = ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    FOR( tc , 1 , t ) {
        scanf("%lld %lld",&L,&R);
        calc( R );
        mem( dp , -1 );
        LL ans = go( 0 , 0 , 0 , 1 );
        calc( L-1 );
        mem( dp , -1 );
        ans -= go( 0 , 0 , 0 , 1 );
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}






