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
    int n , m;
    cin >> n >> m;
    double mn = 10000000.0;
    for( int i = 1; i <= n; i++ ) {
        int a , b;
        cin >> a >> b;
        mn = min( mn , (double)1.0*m*a/b );
    }
    cout << setprecision(10) << fixed << mn << endl;
    return 0;
}

