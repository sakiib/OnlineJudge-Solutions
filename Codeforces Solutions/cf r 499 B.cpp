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

int n , k;
LL a[ N ];
vector <int> V;

bool can( int d ) {

}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 0; i < 9; i++ ) {
                if( can( i ) ) {
                        V.push_back( i );
                        cout << i << " ";
                }
        }
        cout << V.size() << endl;
        for( auto x : V ) cout << x << " ";
        return 0;
}






