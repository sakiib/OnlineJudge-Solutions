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

int n , m , a[ N ];
int mn , mx;

int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> m;
        priority_queue < int , vector <int> , greater<int> > Q;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i] , mx = max( mx , a[i] ) , Q.push( a[i] );
        }
        mx += m;
        while( m ) {
                int t = Q.top();
                Q.pop();
                Q.push( t+1 );
                m--;
        }
        while( !Q.empty() ) {
                mn = max( mn , Q.top() );
                Q.pop();
        }
        cout << mn << " " << mx << endl;
        return 0;
}
