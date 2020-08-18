#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;

/// first player - A , second player - B
/// Winner- who takes the last few coins
/// bottom-up dp
int x , y , n;
int win[ 1000005 ];

int main( ) {
        while( cin >> x >> y >> n ) {
            memset( win , 0 , sizeof( win ) );
            win[0] = 0;
            win[1] = 1;
            win[x] = 1;
            win[y] = 1;
            for( int i = 2; i <= 1e6; i++ ) {
                if( win[i-1] == 0 || ( i >= x  && win[i-x] == 0 ) ||
                    ( i >= y && win[i-y] == 0 ) ) win[i] = 1;
                else win[i] = 0;
            }
            for( int i = 1; i <= n; i++ ) {
                int val;
                cin >> val;
                if( win[val] ) cout << "A";
                else cout << "B";
            }
            cout << endl;
        }
        return 0;
}







