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

int len;
string a , b;
set <string> S;
string res = "";
map < pair<int,int>,int> M;
LL ans;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> len >> a >> b;
        for( int i = 0; i < len; i++ ) {
                if( a[i] == '1' || b[i] == '1' ) res += '1';
                else res += '0';
                M[ {a[i]-'0',b[i]-'0'} ]++;
        }
        for( int i = 0; i < len; i++ ) {
                int x = a[i]-'0' , y = b[i]-'0';
                M[ {x,y} ]--;
                if( x == 1 && y == 1 ) {
                        ans += M[ {0,0} ];
                }
                else if( x == 0 && y == 0 ) {
                        ans += M[ {1,0} ];
                        ans += M[ {1,1} ];
                }
                else if( x == 1 && y == 0 ) {
                        ans += M[ {0,1} ];
                        ans += M[ {0,0} ];
                }
                else if( x == 0 && y == 1 ) {
                        ans += M[ {1,0} ];
                }
        }
        cout << ans << endl;
        return 0;
}






