#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , m , a[ N ];

int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> m;
        int sum = m , mx = 0;
        for( int i = 0; i < n; i++ ) {
                cin >> a[i];
                sum += a[i];
                mx = max( mx , a[i] );
        }
        int c = sum/n;
        if( sum%n != 0 ) c++;
        if( mx > c ) c = mx;
        mx += m;
        cout << c << " " << mx << endl;
        return 0;
}







