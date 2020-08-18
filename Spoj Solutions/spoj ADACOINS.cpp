#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , q , a[ N ];
int dp[ N ];
int ans[ N ];
bitset <N> B;

/**
 How many different amouns can be made using these coins exactly once.
 */

void NormarDP( ) {
        /// TLE
        dp[0] = 1;
        for( int i = 1; i <= n; i++ ) {
                for( int j = 100000; j - a[i] >= 0; j-- ) {
                        dp[j] |= dp[ j - a[i] ];
                }
        }
        for( int i = 1; i <= 100000; i++ ) {
                if( dp[i] == 1 ) ans[i] = ans[i-1] + 1;
                else ans[i] = ans[i-1];
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d %d",&n,&q);
        B[0]= 1;
        for( int i = 1; i <= n; i++ ) {
                scanf("%d",&a[i]);
                B |= ( B << a[i] );
        }
        for( int i = 1; i <= 100000; i++ ) {
                if( B[i] == 1 ) ans[i] = ans[i-1] + 1;
                else ans[i] = ans[i-1];
        }
        while( q-- ) {
                int l , r;
                scanf("%d %d",&l,&r);
                printf("%d\n",ans[r]-ans[l-1]);
        }
        return 0;
}






