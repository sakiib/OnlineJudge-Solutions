/*
Bruteforce solution just to check
wheather the Idea is ok or not !!
This must give TLE !!
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;
const LL inf = 1e15;
LL ara[ N ];
LL mx;

int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for ( int i = 1; i <= n; i++ ){
        scanf("%lld",&ara[i]);
    }
    mx = -inf;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            LL sum = 0;
            for ( int k = i; k < j; k++ ) {
                sum += abs( ara[k]-ara[k+1] )*( (k-i)%2 == 0 ? 1:-1 );
            }
            mx = max( mx , sum );
        }
    }
    printf("%lld\n",mx);
    return 0;
}
