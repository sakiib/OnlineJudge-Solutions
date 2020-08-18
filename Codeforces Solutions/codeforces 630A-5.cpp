#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

LL ara[ 100 ];

bool ok( int num ) {
    for( int i = 2; i <= 10; i++ ) {
        if( num%i == 0 ) return false;
    }
    return true;
}
void test( ) {
    for( int i = 1; i <= 110; i++ ) {
        if( ok( i ) ) cout << i << endl;
    }
}
LL LCM( LL x , LL y ) {
    return ( x*y/__gcd(x,y) );
}
int main( int argc, char const *argv[] ) {
    //test( );
    LL n;
    cin >> n;
    int idx = 0;
    for( int i = 2; i <= 10; i++ ) {
        ara[ i ] = n/i;
    }
    LL lcm = 1LL;
    for( LL i = 2; i <= 10; i++ ) {
        lcm = LCM( lcm , i );
    }
    LL tot = 0 , k = 1;
    for( int i = 2; i <= 10; i++ ) {
        ara[i] = ara[i]-(n/lcm);
        cout << ara[i] << " "<< i <<endl;
    }
    cout << ara[2]+ara[3]+ara[5]+ara[7] <<endl;
    return 0;
}
