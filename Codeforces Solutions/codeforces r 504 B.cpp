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

int n , k , a[ N ];

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        cin >> k;
        vector <int> V;
        for( int i = 1; i <= n; i++ ) {
                if( (i&1) && k > 0 ) V.push_back( i ) , k--;
        }
        for( int i = 0; i < V.size(); i++ ) {
                if( i == 0 ) cout << V[i];
                else cout << " " << V[i];
        }
        cout << endl;
        return 0;
}






