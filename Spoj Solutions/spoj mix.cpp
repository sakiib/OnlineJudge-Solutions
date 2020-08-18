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

int n , a[ N ] , sum[ N ];
int dp[ N ];

int solve( int l , int r ) {
        int ret = inf;
        for( int i = l; i <= r; i++ ) {
                ret = min( ret , solve( l , i ) );
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        while( cin >> n ) {
                memset( sum , 0 , sizeof(sum) );
                for( int i = 1; i <= n; i++ ) cin >> a[i] , sum[i] += sum[i-1]+a[i];
                memset( dp , -1 , sizeof(dp) );
                cout << solve( 1 , n ) << endl;
        }
        return 0;
}






