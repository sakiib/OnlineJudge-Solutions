#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    n++;
    if( n == 1 ) return cout << 0 << endl,0;
    if( n&1 ) cout << n << endl;
    else cout << n/2 << endl;
    return 0;
}






