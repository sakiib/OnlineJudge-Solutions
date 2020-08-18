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
    int a , b , c;
    while( cin >> a >> b >> c ) {
        double s = (a+b+c)*0.5;
        double tri = sqrt( s*(s-a)*(s-b)*(s-c) );
        double rad = ( a*b*c )/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
        double circle = PI*rad*rad;
        double Y = circle-tri;
        double r = tri*2.0/(a+b+c);
        double choto = PI*r*r;
        double P = tri-choto;
        double red = choto;
        double V = tri-red;
        cout << setprecision(4)<<fixed << Y << " " << V << " "<<red << endl;
    }
    return 0;
}

