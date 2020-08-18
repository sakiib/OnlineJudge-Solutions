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

int ara[ 105 ][ 105 ];

int main( int argc, char const *argv[] ) {
    int u , v;
    int t = 1;
    while( scanf("%d%d",&u,&v) ) {
        if( u == 0 && v == 0 ) break;
        for( int i = 1; i <= 100; i++ ) {
            for( int j = 1; j <= 100; j++ ) {
                if( i == j ) ara[i][j] = 0;
                else ara[i][j] = inf;
            }
        }
        ara[u][v] = 1;
        while( scanf("%d%d",&u,&v) ) {
            if( u == 0 && v == 0 ) break;
            ara[u][v] = 1;
        }
        for( int k = 1; k <= 100; k++ ) {
            for( int i = 1; i <= 100; i++ ) {
                for( int j = 1; j <= 100; j++ ) {
                    ara[i][j] = min( ara[i][j] , ara[i][k]+ara[k][j] );
                }
            }
        }
        int dist = 0 , k = 0;
        for( int i = 1; i <= 100; i++ ) {
            for( int j = 1; j <= 100; j++ ) {
                if( ara[i][j] != inf && ara[i][j] != 0 ) {
                    dist += ara[i][j];
                    k++;
                }
            }
        }
        printf("Case %d: average length between pages = ",t++);
        cout << setprecision( 3 ) << fixed << 1.0*dist/k ;
        printf(" clicks\n");
    }
    return 0;
}

