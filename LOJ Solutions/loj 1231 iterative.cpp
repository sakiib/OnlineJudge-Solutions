#include <bits/stdc++.h>
using namespace std;

int n , tot;
int coin[ 55 ] , has[ 55 ];
int ways[ 1005 ];

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
               scanf("%d %d",&n,&tot);
               for( int i = 1; i <= n; i++ ) {
                        scanf("%d",&coin[i]);
               }
               for( int i = 1; i <= n; i++ ) {
                        scanf("%d",&has[i]);
               }
               memset( ways , 0 , sizeof(ways) );
               ways[0] = 1;
               for( int i = 1; i <= n; i++ ) {
                        for( int j = 1; j <= n; j++ ) {
                                for( int k = coin[i]; k <= tot; k++ ) {
                                        ways[k] += ways[k-coin[i]];
                                }
                        }
               }
               printf("Case %d: %d\n",tc,ways[tot]);
        }
        return 0;
}
