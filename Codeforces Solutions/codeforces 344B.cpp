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
    LL a , b , c;
    cin >> a >> b >> c;
    if( (a+b+c)%2 ) {
        cout <<"Impossible"<<endl;
        return 0;
    }
    LL x , y , z;
    y = (b-a+c)/2;
    x = (a+b-c)/2;
    z = c-y;
    if( x < 0 || y < 0 || z < 0 ) cout <<"Impossible"<<endl;
    else cout << x << " " << y << " " << z <<endl;
    return 0;
}

