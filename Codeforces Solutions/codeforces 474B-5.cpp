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

LL n;
LL ara[ N ] , sum[ N ];

struct segment {
    LL l , r;
} temp[ N ];


LL Binary_Search( LL val ) {
    LL lo = 1 , hi = n;
    LL ans = -1;
    while( lo <= hi ) {
        LL mid = (lo+hi)/2;
        if( val <= temp[mid].r && val >= temp[mid].l ) {
            ans = mid;
            return ans;
        }
        else if( val < temp[mid].l ) hi = mid-1;
        else lo = mid+1;
    }
}
int main( int argc, char const *argv[] ) {
    scanf("%lld",&n);
    LL prev = 1;
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        sum[i] = sum[i-1]+ara[i];
    }
    for( int i = 1; i <= n; i++ ) {
        if( i == 1 ) {
            temp[i].l = 1;
            temp[i].r = sum[i];
        }
        else {
            temp[i].l = sum[i]-ara[i]+1;
            temp[i].r = sum[i];
        }
    }
    int q;
    scanf("%d",&q);
    while( q-- ) {
        LL val;
        scanf("%lld",&val);
        printf("%lld\n",Binary_Search( val ) );
    }
    return 0;
}

