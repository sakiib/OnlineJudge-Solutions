#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

int main( int argc, char const *argv[] ) {
    string a , b;
    cin >> a >> b;
    int x = 0 , y = 0;
    for( int i = 0; i < a.size(); i++ ) {
        if( a[i] == '7' && b[i] == '4' ) x++;
        else if( a[i] == '4' && b[i] == '7' ) y++;
    }
    int ans = min( x , y );
    ans += max( x , y) - min( x , y );
    cout << ans << endl;
    return 0;
}

