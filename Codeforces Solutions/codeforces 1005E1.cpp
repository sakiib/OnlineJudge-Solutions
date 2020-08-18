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

int n , m;
int a[ 2*N ];
int ans;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        // TLE -> O(N^3) .. Just Testing ..
        for( int i = 1; i <= n; i++ ) {
                for( int j = i; j <= n; j++ ) {
                        int small = 0 , big = 0;
                        bool f = false;
                        for( int k = i; k <= j; k++ ) {
                              if( a[k] > m ) big++;
                              else if( a[k] <  m ) small++;
                              else f = true;
                        }
                        if( (small == big || small+1 == big) && f ) {
                                ans++;
                        }
                }
        }
        cout << ans << endl;
        return 0;
}






