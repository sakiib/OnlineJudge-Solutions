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
    int t;
    scanf("%d",&t);
    while( t-- ) {
        string num;
        cin >> num;
        int pos = num.find( '.' );
        if( pos == -1 ) {
            cout << 1 << endl;
            continue;
        }
        int p = 1;
        for( int i = pos+1; i < num.size(); i++ ) {
            p *= 10;
        }
        int n = 0;
        for( int i = 0; i < num.size(); i++ ) {
            if( num[i] == '.' ) continue;
            n = n*10+num[i]-'0';
        }
        int g = __gcd( n , p );
        cout << p/g << endl;
    }
    return 0;
}

