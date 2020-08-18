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

int ara[ 2*N ];
int BIT[ 100*N ];

void Update( int idx , int val ) {
    for( ; idx <= 100*N; idx += (idx & -idx ) ) {
        BIT[idx] += val;
    }
}
LL Query( int idx ) {
    LL ret = 0;
    for( ; idx > 0 ; idx -= ( idx & -idx ) ) {
        ret += BIT[idx];
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        LL ans = 0;
        for( int i = n; i >= 1; i-- ) {
            ans += Query( ara[i]-1 );
            Update( ara[i] , +1 );
        }
        printf("%lld\n",ans);
        memset( BIT , 0 , sizeof(BIT) );
    }
    return 0;
}

