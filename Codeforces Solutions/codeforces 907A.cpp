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
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    if( c > 2*d || d > 2*c || d >= b ) cout << -1 << '\n';
    else {
        int x = 2*a , y = 2*b;
        int z = ( c > d ? c : d );
        cout << x << '\n' << y << '\n' << z << '\n';
    }
    return 0;
}

