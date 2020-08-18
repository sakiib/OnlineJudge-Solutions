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

int a[ N ];
double ans[ N ];

int main( int argc, char const *argv[] ) {
    int n , r;
    cin >> n >> r;
    for( int i = 1; i <= n; i++ ) {
        cin >> a[i];
    }
    for( int i = 1; i <= n; i++ ) {
        if( i == 1 ) {
            ans[ i ] = r;
            continue;
        }
        int p = a[i];
        bool f = false;
        double mx = 0;
        for( int j = i-1; j >= 1; j-- ) {
            if( ( p+r >= a[j]-r  ) && ( p-r <= a[j]+r) ) {
                double b = 2.0*ans[j];
                double c = ans[j]*ans[j];
                c += ( (p-a[j])*(p-a[j]) );
                c -= ( 4*r*r );
                double res = b+sqrt( abs(b*b - (4.0*c) ) );
                res = res/2.0;
                mx = max( mx , res );
                f = true;
            }
        }
        ans[i] = mx;
        if( !f ) ans[i] = r;
    }
    for( int i = 1; i <= n; i++ ) {
        cout << setprecision(10) << fixed << ans[i] <<" ";
    }
    return 0;
}
