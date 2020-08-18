#include <bits/stdc++.h>
using namespace std;

int n;
int a[ 15 ];
int tot;

int main( int argc, char const *argv[] ) {
        cin >> n;
        for( int i = 0; i < n; i++ ) cin >> a[i] , tot += a[i];
        for( int i = 0; i < ( 1 << n ); i++ ) {
                vector < pair <int,int> > V;
                for( int j = 0; j < n; j++ ) {
                        if( ( i&( 1 << j ) ) > 0 ) {
                             V.push_back( {a[j],j} );
                        }
                }
                int g = 0;
                for( auto x : V ) g += x.first;
                int f = 0;
                f = tot-g;
                int ghas = 0 , fhas = 0;
                ghas = (int)V.size() , fhas = n-ghas;
                if( ghas+fhas == n && ghas > 0 && fhas > 0 && g != f && g > 0 && f > 0 ) {
                        cout << (int)V.size() << endl;
                        for( auto x : V ) cout << x.second+1 << " ";
                        return 0;
                }
        }
        cout << -1 << endl;
        return 0;
}






