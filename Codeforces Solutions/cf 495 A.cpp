#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 100005;

const LL INF = 1e18;
LL a[ N ];
set < LL > S;

int main( int argc, char const *argv[] ) {
        int n;
        LL d;
        cin >> n >> d;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) {
                LL pos = a[i]-d;
                LL mn = INF;
                for( int j = 1; j <= n; j++ ) {
                    mn = min( mn , abs( a[j]-pos ) );
                }
                if( mn == d ) S.insert( pos );
                pos = a[i]+d;
                mn = INF;
                for( int j = 1; j <= n; j++ ) {
                    mn = min( mn , abs( a[j]-pos ) );
                }
                if( mn == d ) S.insert( pos );
        }
        cout << (int)S.size() << endl;
        return 0;
}






