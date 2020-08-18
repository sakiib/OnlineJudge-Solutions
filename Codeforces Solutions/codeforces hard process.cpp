#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int ara[ N ], sum[ N ];

int main( int argc,char const *argv[] ) {
    int n, k;
    scanf("%d%d",&n,&k);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d",&ara[i]);
    }
    for ( int i = 1; i <= n; i++ ) {
        sum[i] += sum[i-1]+( ara[i] == 0 ? 1 : 0 );
    }
    int j = 1;
    int lo = 0, hi = -1;
    int dif = 0;
    int l = 0, r = 0;
    for ( int i = 1; i <= n;  ) {
        if ( sum[i]-sum[j-1] <= k ) {
            lo = j, hi = i;
            i++;
        }
        else j++;
        if ( hi-lo+1 > dif ) {
            dif  = hi-lo+1;
            l = lo, r = hi;
        }
    }
    printf("%d\n",dif);
    for ( int i = 1; i <= n; i++ ) {
        if ( i>=l && i<=r ) printf("1 ");
        else printf("%d ",ara[i]);
    }
    return 0;
}
