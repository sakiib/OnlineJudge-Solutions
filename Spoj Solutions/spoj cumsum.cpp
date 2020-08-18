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

LL ara[ 10*N ];

int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
    }
    for( int i = 1; i <= n; i++ ) {
        ara[i] += ara[i-1];
    }
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int l , r;
        scanf("%d%d",&l,&r);
        l++ , r++;
        printf("%lld\n",ara[r]-ara[l-1]);
    }
    return 0;
}

