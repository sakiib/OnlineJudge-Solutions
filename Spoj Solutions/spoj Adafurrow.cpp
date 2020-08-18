#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 2e4 + 1;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

bitset <N> B[ N ];

int main( int argc , char const *argv[] ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
                getchar();
                char c;
                int x , y;
                scanf("%c",&c);
                scanf("%d %d",&x,&y);
                if( c == '+' ) {
                        /// Turn on y'th bit of x.
                        B[x][y] = 1;
                }
                else if( c == '-' ) {
                        /// Turn off y'th bit of x.
                        B[x][y] = 0;
                }
                else if( c == 'v' ) {
                        /// Total on Bits of x & y.
                        int ans = (B[x] | B[y]).count();
                        printf("%d\n",ans);
                }
                else if( c == '^' ) {
                        /// Total same Bit on count.
                        int ans =  (B[x] & B[y]).count();
                        printf("%d\n",ans);
                }
                else if( c == '!' ) {
                        /// On Bit Have in x but not in Both.
                        int ans = ( B[x] | B[y] ).count() - ( B[x] & B[y] ).count();
                        printf("%d\n",ans);
                }
                /// On Bit Have in x but not in y.
                else {
                        int ans = B[x].count() - ( B[x] & B[y] ).count();
                        printf("%d\n",ans);
                }
        }
        return 0;
}






