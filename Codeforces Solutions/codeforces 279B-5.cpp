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

LL n , ara[ N ] , t;

int main( int argc, char const *argv[] ) {
    scanf("%lld%lld",&n,&t);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    for( int i = 1; i <= n; i++ ) {
        ara[i] += ara[i-1];
    }
    LL ans = 0;
    for( int i = 1; i <= n; i++ ) {

    }
    printf("%lld\n",ans);
    return 0;
}

