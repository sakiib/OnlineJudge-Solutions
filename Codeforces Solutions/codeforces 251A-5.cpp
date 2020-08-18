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

LL n , d;
LL ara[ N ];

int main( int argc, char const *argv[] ) {
    scanf("%lld%lld",&n,&d);
    for( int i = 1; i <= n; i++ ) scanf("%lld",&ara[i]);
    LL ans = 0;
    for( int i = 1; i <= n; i++ ) {
        int l = i;
        int r = upper_bound( ara+i , ara+n+1 , ara[i]+d )-ara;
        r--;
        LL len = r-l;
        ans += ( len*(len-1)/2 );
    }
    printf("%lld\n",ans);
    return 0;
}

