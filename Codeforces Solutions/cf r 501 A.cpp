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

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n , m;
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) {
                int l , r;
                cin >> l >> r;
                for( int j = l; j <= r; j++ ) a[j] = 1;
        }
        vector <int> V;
        for( int i = 1; i <= m; i++ ) if( a[i] == 0 ) V.push_back( i );
        cout << V.size() << endl;
        for( auto x : V ) cout << x << " ";
        return 0;
}






