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

LL val[ 100 ];

void calc( ) {
    val[0] = 1LL;
    for( LL i = 1; i <= 62; i++ ) {
        val[i] = val[i-1]*2;
    }
}
int main( int argc, char const *argv[] ) {
    calc( );
    LL sum , n;
    cin >> sum >> n;

    return 0;
}

