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

const LL sz = N+50005;

LL ara[ sz ] , BIT[ sz ];
char s[ 10 ];

void Update( LL idx , LL val ) {
    for( ; idx <= sz; idx += ( idx & -idx ) ) {
        BIT[idx] += val;
    }
}
LL Query( LL idx ) {
    LL sum = 0;
    for( ; idx > 0; idx -= ( idx & -idx ) ) {
        sum += BIT[idx];
    }
    return sum;
}
LL Binary_Search( LL l , LL r , LL val ) {
    LL lo = 1 , hi = r , ret = 0;
    while( lo <= hi ) {
        int mid = (lo+hi)/2;
        if( Query( mid ) >= val ) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL n , q;
        scanf("%lld%lld",&n,&q);
        LL tot = n , idx = n;
        for( int i = 1; i <= n; i++ ) {
            scanf("%lld",&ara[i]);
            Update( i , 1 );
        }
        printf("Case %d:\n",tc);
        while( q-- ){
           scanf("%s",s);
           if( s[0] == 'c' ) {
             LL k;
             scanf("%lld",&k);
             if( k > tot ) {
                printf("none\n");
                continue;
             }
             else {
                tot--;
                LL pos = Binary_Search( 1 , sz , k );
                printf("%lld\n",ara[pos]);
                Update( pos , -1 );
             }
           }
           else {
            LL k;
            scanf("%lld",&k);
            ara[ ++idx ] = k;
            Update( idx , 1 );
            tot ++;
           }
        }
        memset( BIT , 0 , sizeof( BIT ) );
    }
    return 0;
}

