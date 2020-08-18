#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 100005;
typedef long long int LL;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

template < typename T >
using orderset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset <int> S;

int a[ 2*N ];

int main( int argc, char const *argv[] ) {
        fast_io;
        int t;
        cin >> t;
        while( t-- ) {
                int n;
                cin >> n;
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                LL ans = 0;
                for( int i = n; i >= 1; i-- ) {
                        int pos = S.order_of_key( a[i] );
                        ans += (pos);
                        S.insert( a[i] );
                }
                cout << ans << endl;
                S.clear();
        }
        return 0;
}






