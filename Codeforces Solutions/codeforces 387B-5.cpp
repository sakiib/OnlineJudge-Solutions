#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
vector <int> V;
int need[ N ] , has[ N ];
int ans;

int main( int argc , char const *argv[] ) {
        int n , m;
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) cin >> need[i];
        for( int i = 1; i <= m; i++ ) cin >> has[i] , V.push_back( has[i] );
        sort( V.begin() , V.end() );
        for( int i = 1; i <= n; i++ ) {
                if( V.binary_search( V.begin() , V.end() , need[i]) ) {

                }
        }
        cout << ans << endl;
        return 0;
}
