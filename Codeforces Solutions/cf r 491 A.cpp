#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template < typename T >
using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

orderset <int> treap;
typedef long long LL;
const LL INF = (LL)(1e18);
const int N = 100005;
int n , k;
int a[ N ];
int ans;
LL mx = INF;

int main( int argc, char const *argv[] ) {
        cin >> n >> k;
        for( int kk = 1; kk <= k; kk++ ) {
                treap.clear();
                for( int i = 1; i <= n; i++ ) {
                        cin >> a[i];
                }
                LL inv = 0;
                for( int i = 1; i <= n; i++ ) {
                        int pos = treap.order_of_key( a[i] );
                        inv += pos;
                        treap.insert( a[i] );
                }
                if( inv < mx ) mx = inv , ans = kk;
        }
        cout << ans << endl;
        return 0;
}





