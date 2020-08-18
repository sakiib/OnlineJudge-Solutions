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
    int n;
    cin >> n;
    if( n%10 == 0 ) {
        cout << n << endl;
        return 0;
    }
    int x = n;
    int y = n;
    int t1 = 0, t2 = 0;
    while( x%10 != 0 ) {
        x++;
        t1++;
    }
    while( y%10 != 0 ) {
        y--;
        t2++;
    }
    if( t1 < t2 ) cout << x << endl;
    else cout << y << endl;
    return 0;
}



