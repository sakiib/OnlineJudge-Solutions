#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Fix( x ) setprecision( x ) << fixed

const int N = 100005;

int a[ N ] , sum[ N ];
int n , k;
double mx = -1e15;

void solve( int len ) {
        int l = 1 , r = len;
        while( r <= n ) {
                int tot = sum[r] - sum[l-1];
                double avg = 1.0*tot/len;
                mx = max( mx , avg );
                l++ , r = ( l+len-1 );
        }
}
int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , sum[i] += sum[i-1]+a[i];
        while( k <= n ) {
                solve( k );
                k++;
        }
        cout << Fix(20) << mx << endl;
        return 0;
}






