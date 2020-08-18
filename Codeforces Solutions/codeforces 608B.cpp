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

int cum[ 2*N ] = {0};

int main( int argc, char const *argv[] ) {
    string a , b;
    cin >> a >> b;
    int la = a.size();
    int lb = b.size();
    a = " "+a;
    b = " "+b;
    for( int i = 1; i <= lb; i++ ) {
        cum[i] += ( cum[i-1] + ( b[i]-'0') );
    }
    LL ans = 0;
    for( int i = 1; i <= la; i++ ) {
        int l = i;
        int r = lb-la+i;
        int one = cum[r]-cum[l-1];
        if( a[i] == '0' ) {
            ans += one;
        }
        else {
            int len = r-l+1;
            int zero = len-one;
            ans += zero;
        }
    }
    cout << ans << endl;
    return 0;
}
