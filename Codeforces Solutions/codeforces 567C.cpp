#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;

int n , k;
LL a[ 2*N ];
map < LL , LL > tot , L , R;
LL ans;

int main( int argc , char const *argv[] ) {
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                R[ a[i] ]++;
        }
        for( int i = 1; i <= n; i++ ) {
                R[ a[i] ]--;
                if( a[i]%k == 0 ) {
                        LL l = a[i]/k , r = a[i]*k;
                        ans += ( L[l] * R[r] );
                }
                L[ a[i] ]++;
        }
        cout << ans << endl;
        return 0;
}
