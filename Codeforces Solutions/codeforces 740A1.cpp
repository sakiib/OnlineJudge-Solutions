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

int main( int argc, char const *argv[] ) {
    LL n , a , b , c;
    cin >> n >> a >> b >> c;
    if( n%4 == 0 ) return cout << 0 << endl , 0;
    LL x = n/4+1;
    LL y = n*4;
    LL need = y-x;

    return 0;
}

