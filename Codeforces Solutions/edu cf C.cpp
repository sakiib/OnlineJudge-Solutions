#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

vector <int> V;
int len;
int dp[ 19 ][ 2 ][ 19 ];

LL go( int pos , int chk , int cnt ) {
        if( pos >= len ) return ( cnt <= 3 );
        if( dp[pos][chk][cnt] != -1 ) return dp[pos][chk][cnt];
        LL ret = 0;
        if( chk ) {
                for( int i = 0; i <= 9; i++ ) {
                       ret += go( pos+1 , 1 , cnt + ( i != 0 ) );
                }
        }
        else {
                for( int i = 0; i < V[pos]; i++ ) {
                       ret += go( pos+1 , 1 , cnt + ( i != 0 ) );
                }
                ret += go( pos+1 , 0 , cnt + ( V[pos] != 0 ) );
        }
        return dp[pos][chk][cnt] = ret;
}
LL solve( LL x ) {
        V.clear();
        while( x ) V.push_back( x%10 ) , x /= 10;
        len = V.size();
        reverse( V.begin() , V.end() );
        memset( dp , -1 , sizeof(dp) );
        return go( 0 , 0 , 0 );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        while( t-- ) {
                LL a , b;
                scanf("%lld %lld",&a,&b);
                printf("%lld\n",solve( b ) - solve( a - 1 ));
        }
        return 0;
}
