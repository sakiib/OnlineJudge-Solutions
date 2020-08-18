#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int NOD[ N ];
int val[ N ];

void calc() {
    for ( int i = 1; i <= N; i++ ) {
        for ( int j = i; j <= N; j+=i ) {
            NOD[j] ++;
        }
    }
    val[0] = 1;
    for ( int i = 1; i <= N; i++ ) {
        val[ i ] = val[ i-1 ] + NOD[ val[ i-1 ] ];
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    calc();
    scanf("%d",&t);
    for ( int tc  = 1; tc <= t; tc++ ) {
        int a, b;
        scanf("%d%d",&a,&b);
        int up = upper_bound( val, val+N+1, b) - val;
        int lo = lower_bound( val, val+N+1, a) - val;
        printf("Case %d: %d\n",tc,(up-lo));
    }
    return 0;
}
