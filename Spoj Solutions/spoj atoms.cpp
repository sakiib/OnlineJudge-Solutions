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

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        LL n , k , m;
        scanf("%lld %lld %lld",&n,&k,&m);
        double res = n;
        LL ans = 0;
        while( res <= m ) {
            ans++;
            res *= k;
        }
        if( ans > 0 ) printf("%lld\n",ans-1);
        else printf("0\n");
    }
    return 0;
}
