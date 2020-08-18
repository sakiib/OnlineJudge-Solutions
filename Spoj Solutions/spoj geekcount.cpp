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

int prodigi( int x ) {
    int ret = 1;
    while( x ) {
        ret *= x%10;
        x /= 10;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    for( int i = 1; i <= 1000; i++ ) {
        if( prodigi( i )%2 == 0 ) cout << i << endl;
    }
    return 0;
}

