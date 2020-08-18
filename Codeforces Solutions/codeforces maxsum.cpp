#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ 705 ][ 705 ];
int n;
LL mx = -1;

void dfs( int idx , LL prev , LL sum ) {
    if( idx == n+1 ) {
        mx = max( mx , sum );
        return;
    }
    for( ; idx <= n; idx++ ) {
        for( int j = 1; j <= n; j++ ) {
            if( ara[idx][j] > prev ) {
                dfs( idx+1 , ara[idx][j] , sum+ara[idx][j] );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                scanf("%lld",&ara[i][j]);
            }
        }
        for( int i = 1; i <= n; i++ ) {
            sort( ara[i]+1 , ara[i]+n+1 ); reverse( ara[i]+1 , ara[i]+n+1 );
        }
        mx = -1;
        for( int i = 1; i <= n; i++ ) {
            dfs( 2 , ara[1][i] , ara[1][i] );
            if( mx != -1 ) break;
        }
        printf("%lld\n",mx);
    }
    return 0;
}

