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
    int vala = 0 ;
    for( int i = 0; i < a.size(); i++ ) {
        (a[i] == '+' ? vala++ : vala--);
    }
    int valb = 0;
    int wh = 0;
    for( int i = 0; i < b.size(); i++ ) {
        if( b[i] == '+' ) valb++;
        else if( b[i] == '-' ) valb--;
        else wh++;
    }
    if( !wh ) {
        if( vala == valb ) cout << 1.00000000 << endl;
        else cout << 0.000000000 << endl;
        return 0;
    }
    vector <int> V;

    for( int i = 0; i < V.size(); i++ ) {
        cout << V[i] << endl;
    }
    //cout << setprecision(15) << fixed << op*1.0/tot << endl;
    return 0;
}

