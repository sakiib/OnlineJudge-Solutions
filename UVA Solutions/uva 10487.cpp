#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
const int N = 1005;
int ara[ N ];
int n;

int main( int argc, char const *argv[] ) {
    int tc = 1;
    while ( scanf("%d",&n) ) {
        if ( n == 0 ) break;
        for ( int i = 1; i <= n; i++ ) {
            scanf("%d",&ara[i]);
        }
        sort( ara+1, ara+n+1 );
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc++);
        while( q-- ) {
            int val;
            int res = inf , sum = 0;
            scanf("%d",&val);
            int l = 1, r = n;
            while ( l < r ) {
                sum = ara[l]+ara[r];
                ( sum > val ) ? r-- : l++;
                if ( abs( sum-val ) < abs( val-res ))
                    res = sum;
            }
            printf("Closest sum to %d is %d.\n",val,res);
        }
    }
    return 0;
}

