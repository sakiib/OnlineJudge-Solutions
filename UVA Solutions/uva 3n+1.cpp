#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a , b;
LL mx;

void solve( LL n , LL length ) {
    if( n == 1 ) {
        mx = max( mx , length );
        return;
    }
    if( n%2 == 0 ) solve( n/2 , length+1 );
    else solve( 3*n+1 , length+1 );
}
int main( int argc, char const *argv[] ) {
    while( scanf("%lld %lld",&a,&b) != EOF ) {
        mx = 0;
        LL x = a , y = b;
        if( a > b ) swap( a , b );

        for( LL i = a; i <= b; i++ ) {
            solve( i , 1 );
        }
        printf("%lld %lld %lld\n",x,y,mx);
    }
    return 0;
}

