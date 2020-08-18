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

LL n;
map <LL,int> M;

int can_win( LL cur , int n ) {
        cout << cur << endl;
        if( cur >= n ) return 1;
        if( M[cur] != 0 ) return M[cur];
        for( int i = 2; i <= 9; i++ ) {
                if( can_win( cur * i , n ) == 1 ) {
                        return M[cur] = 2;
                }
        }
        cout << "here : " << cur << endl;
        return M[cur] = 1;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        while( cin >> n ) {
                M.clear();
                if( can_win( 1 , n ) == 1 ) cout << "Ollie wins." << endl;
                else cout << "Stan wins." << endl;
        }
        return 0;
}






