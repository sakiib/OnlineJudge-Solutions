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

const int sz = 800;

LL n;
LL ara[ sz ][ sz ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%lld",&n);
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                scanf("%lld",&ara[i][j]);
            }
        }
        LL mx = -1 , last = INF , ans = 0;
        bool f = true;
        for( int i = n; i >= 1; i-- ) {
            mx = -1;
            for( int j = 1; j <= n; j++ ) {
                if( ara[i][j] > mx && ara[i][j] < last ) {
                    mx = ara[i][j];
                }
            }
            if( mx == -1 ) {
                f = false;
            }
            else {
                ans += mx;
                last = mx;
            }
        }
        if( !f ) printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}

