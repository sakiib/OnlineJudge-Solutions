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
    LL n;
    while( scanf("%lld",&n) ) {
        if( n < 0 ) break;
        LL ans = n*(n+1)/2;
        ans++;
        printf("%lld\n",ans);
    }
    return 0;
}

