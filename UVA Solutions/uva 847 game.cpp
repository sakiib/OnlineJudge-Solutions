#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n;

bool solve( LL x ) {
    if( x >= n ) return 0;
    if( solve( x*2 ) == 0 || solve( x*9 ) == 0 ) return 1;
    return 0;
}
int main( int argc, char const *argv[] ) {
    while( scanf("%lld",&n) != EOF ) {
        if( solve( 1 ) ) printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }
    return 0;
}

