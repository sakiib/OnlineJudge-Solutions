#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map <int,int,custom_hash> cnt;
//unordered_map <int,int> cnt;
//map <int,int> cnt;

int n , m;
int a[ 5*N ];
//int cnt[ 10*N ];
int ans;

int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n >> m;
        cnt.max_load_factor( 0.25 );
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        int mx = 1 , len = 1 , i = 1 , j = 1 , taken = 1;
        int st = 1 , en = 1;
        cnt[ a[1] ]++;
        while( i <= n && j <= n ) {
                while( taken <= m && j <= n ) {
                        j++;
                        len++;
                        if( cnt[ a[j] ] == 0 ) taken++;
                        cnt[ a[j] ]++;
                }
                if( len - 1 > mx ) {
                        mx = len - 1;
                        st = i , en = j - 1;
                }
                while( taken > m ) {
                        cnt[ a[i] ]--;
                        if( cnt[ a[i] ] == 0 ) taken--;
                        i++ , len--;
                }
        }
        cout << st << " " << en << endl;
        return 0;
}













