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
    LL a , b1;
    cin >> a >> b1;
    LL y , g , b;
    cin >> y >> g >> b;
    LL Y = 2*y+g;
    LL B = g+3*b;
    LL ans = 0;
    if( Y > a ) ans += (Y-a);
    if( B > b1 ) ans += (B-b1);
    cout << ans <<endl;
    return 0;
}

