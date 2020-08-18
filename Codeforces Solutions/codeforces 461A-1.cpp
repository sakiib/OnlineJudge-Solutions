#include <bits/stdc++.h>
using namespace std;

const int N = 3*100005;
typedef long long LL;
LL ara[ N ];

int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    LL sum = 0;
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        sum += ara[i];
    }

    return 0;
}
