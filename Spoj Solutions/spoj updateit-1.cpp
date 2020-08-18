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

const int sz = 10005;

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
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ){
        int n , u;
        scanf("%d%d",&n,&u);
        while( u-- ) {
            int l , r , val;
            scanf("%d%d%d",&l,&r,&val);
            Update( l , +val );
            Update( r+1 , -val );
        }
        int q;
        scanf("%d",&q);
        while( q-- ) {
            int pos;
            scanf("%d",&pos);
            printf("%d\n",Query( pos ) );
        }
        memset( BIT , 0 , sizeof( BIT ) );
    }
    return 0;
}

