#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int lgN = 20;

int n , q;
int par[ N ][ lgN+5 ];
int val[ N ];

void build_ST( ) {
        for( int i = 1; i <= lgN; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                      if( par[ j ][ i-1 ] != -1 ) {
                            par[ j ][ i ] = par[ par[j][i-1] ][ i-1 ];
                      }
                }
        }
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&q);
                memset( par , -1 , sizeof(par) );
                val[1] = 1;
                for( int i = 2; i <= n; i++ ) {
                        int p , v;
                        scanf("%d %d",&p,&v);
                        ++p;
                        par[i][0] = p;
                        val[i] = v;
                }
                build_ST( );
                printf("Case %d:\n",tc);
                while( q-- ) {
                        int u , v;
                        scanf("%d %d",&u,&v);
                        int ans = u;
                        for( int i = lgN; i >= 0; i-- ) {
                                if( par[u][i] != -1 && val[ par[u][i] ] >= v ) {
                                        u = par[u][i];
                                        ans = u;
                                }
                        }
                        printf("%d\n",ans-1);
                }
        }
        return 0;
}






