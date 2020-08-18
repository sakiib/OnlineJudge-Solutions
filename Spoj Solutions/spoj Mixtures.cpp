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

int a[ N ];
int n;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        while( cin >> n ) {
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                LL ans = INF;
                for( int i = 1; i <= n; i++ ) {
                        memset( dp , -1 , sizeof(dp) );
                        ans = min( ans , solve( i ,  ) );
                }
                cout << ans << endl;
        }
        return 0;
}






