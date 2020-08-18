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

const int sz = 1505;

int ara[ sz ];
int BIT[ sz ];

void Update( int idx , int val ) {
    for( ; idx <= sz; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
int Query( int idx ) {
    int ret = 0;
    for( ; idx > 0; idx -= ( idx & -idx ) ) {
        ret += BIT[idx];
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    int cnt = 0;
    for( int i = n; i >= 1; i-- ) {
        cnt += ( Query( ara[i]-1 ) );
        Update( ara[i] , 1 );
    }
    cnt %= 2;
    int q;
    scanf("%d",&q);
    while( q-- ) {
        int l , r;
        scanf("%d%d",&l,&r);
        int res = (r-l+1);
        int tot = res*(res-1)/2;
        tot %= 2;
        if( tot&1 ) cnt = !cnt;
        if( cnt ) printf("odd\n");
        else printf("even\n");
    }
    return 0;
}

