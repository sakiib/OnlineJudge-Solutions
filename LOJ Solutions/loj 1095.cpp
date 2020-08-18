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

int n , m , k;

LL solve( int pos , int corr ) {
        if( pos >= n ) return ( mm == k ? 1 : 0 );
        LL ret = 0;
        for( int i = 1; i <= n; i++ ) {

        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&m,&k);
                printf("Case %d: %lld\n",tc,solve( 1 , 1 , 0 ));
        }
        return 0;
}






