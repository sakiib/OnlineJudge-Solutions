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

LL ara[ N ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        int n , m;
        scanf("%d %d",&n,&m);
        for( int i = 1; i <= n; i++ ) {
            scanf("%lld",&ara[i]);
        }
        for( int i = 2; i <= n; i++ ) {
            if( ara[i] >= 0 ) continue;
            ara[i] = ( ara[i-1]%m+1%m)%m;
            if( ara[i] < 0 ) ara[i] = ara[i]+m;
            ara[i] %= m;
        }
        for( int i = 1; i <= n; i++ ) {
            printf("%lld ",ara[i]);
        }
        printf("\n");
    }
    return 0;
}

