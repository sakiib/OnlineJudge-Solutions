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

LL n, a, b;

int main( int argc, char const *argv[] ) {
    cin >> n >> a >> b;
    for( LL i = 0; i <= n && i*a <= n; i++ ) {
        if( (n-i*a)%b == 0 ) {
            cout << "YES" << endl << i << " " << (n-i*a)/b << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}




