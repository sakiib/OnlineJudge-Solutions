#include <bits/stdc++.h>
using namespace std;

int fact( int n ) {
    return ( n == 0 ) ? 1 : n*fact( n-1 );
}
int main( int argc, char const *argv[] ) {
    int a, b;
    scanf("%d%d",&a,&b);
    int n = min( a, b);
    printf("%d\n",fact( n ));
    return 0;
}

