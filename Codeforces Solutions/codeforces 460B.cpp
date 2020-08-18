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

vector <LL> ans;

LL Power( LL b , LL p ) {
    LL ret = 1;
    for( LL i = 1; i <= p; i++ ) {
        ret *= b;
    }
    return ret;
}
LL DigitSum( LL num ) {
    LL sum = 0;
    while( num ) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}
int main( int argc, char const *argv[] ) {
    LL a , b , c;
    cin >> a >> b >> c;
    for( LL i = 1; i <= 90; i++ ) {
        LL val = b*Power( i , a )+c;
        if( val < 0 || val >= 1000000000) continue;
        if( DigitSum( val ) == i ) ans.push_back( val );
    }
    cout << ans.size() << endl;
    for( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << " ";
    }
    return 0;
}

