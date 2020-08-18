#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

inline LL ExtGCD( LL a , LL b , LL &x , LL &y ) {
        if( b == 0 ) { x = 1 , y = 0; return a; }
        LL x1 , y1 , gcd = ExtGCD( b , a % b , x1 , y1 );
        x = y1;
        y = x1-(a / b)*y1;
        return gcd;
}
int main( int argc , char const *argv[] ) {
        LL a , b;
        while( cin >> a >> b ) {
                LL x , y;
                LL g = ExtGCD( a , b , x , y );
                cout << x << " " << y << " " << g << endl;
        }
        return 0;
}

