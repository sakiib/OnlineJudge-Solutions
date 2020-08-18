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

int n;
LL a[ 2*N ];
int pos , neg , z;

int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                pos += ( a[i] > 0 );
                neg += ( a[i] < 0 );
                z += ( a[i] == 0 );
        }
        if( pos == n ) {
                for( int i = n-1; i >= 1; i-- ) {
                        cout << 1 << " " << i << " " << n << endl;
                }
                return 0;
        }
        if( neg == n ) {
                if( n&1 ) {
                        if( a[n] < a[1] ) {
                                cout << 2 << " " << 1 << endl;
                                for( int i = n-1; i >= 2; i-- ) {
                                        cout << i << " " <<n << endl;
                                }
                                return 0;
                        }
                        else {
                                cout << 2 << " " << n << endl;
                                for( int i = 1; i <= n-2; i++ ) {
                                        cout << i << " " <<n-1 << endl;
                                }
                                return 0;
                        }
                }
                else {
                        for( int i = n-1; i >= 1; i-- ) {
                                cout << 1 << " " << i << " " << n << endl;
                        }
                        return 0;
                }
        }


        return 0;
}







