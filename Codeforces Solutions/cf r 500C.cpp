#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int a[ 100 ] , b[ 100 ] , x , y;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , x += a[i];
        for( int i = 1; i <= n; i++ ) cin >> b[i] , y += b[i];
        int l = 0 , r = 0;
        for( int i = 1; i <= n; i++ ) {
                if( b[i] < a[i] ) l += abs( a[i]-b[i] );
                else r += ( b[i]-a[i] );
        }
        if( l >= r ) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
}






