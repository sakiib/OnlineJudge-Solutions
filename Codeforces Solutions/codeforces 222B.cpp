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

int n , m , k;
int ara[ 1005 ][ 1005 ];
int r[ 1005 ] , c[ 1005 ];
char str[ 10 ];

int main( int argc, char const *argv[] ) {
    scanf("%d%d%d",&n,&m,&k);
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ) {
            scanf("%d",&ara[i][j]);
        }
    }
    for( int i = 1; i <= n; i++) r[i] = i;
    for( int i = 1; i <= m; i++ ) c[i] = i;
    while( k-- ) {
        int x , y;
        scanf("%s%d%d",str,&x,&y);
        if( str[0] == 'c' ) swap( c[x] , c[y] );
        else if( str[0] == 'r' ) swap( r[x] , r[y] );
        else printf("%d\n",ara[r[x]][c[y]] );
    }
    return 0;
}

