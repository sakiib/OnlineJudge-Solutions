#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int inf = 1000000000;
int ara[ N ];

bool Found( int lo, int hi, int val ) {
    while ( lo <= hi ) {
        int mid = ( lo+hi )/2;
        if ( ara[mid] == val ) return true;
        if ( ara[mid] < val ) lo = mid+1;
        else hi = mid-1;
    }
    return false;
}
int main( int argc, char const *argv[] ) {
    int n;
    while ( scanf("%d",&n) != EOF ){
        for ( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        int tot;
        scanf("%d",&tot);
        sort( ara+1, ara+n+1 );
        int mndif = inf;
        int x = 0, y = 0;
        for ( int i = 1; i < n; i++ ) {
            int val = ara[i];
            int rem = tot-val;
            if ( Found( i+1, n, rem ) ) {
                int dif = abs( rem-x );
                if ( dif < mndif ) {
                   x = val, y = rem;
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
    return 0;
}
