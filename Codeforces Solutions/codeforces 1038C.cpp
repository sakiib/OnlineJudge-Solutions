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

int n , a[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                cin >> n;
                map <int,int> M;
                for( int i = 1; i <= n; i++ ) cin >> a[i] , M[ a[i] ]++;
                for( auto x : M ) if( x.second == 2 ) {
                        cout << x.first << endl;
                        break;
                }
        }
        return 0;
}





