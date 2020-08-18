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

/*
Regular Polygon Interior Angle Formula:
For any equiangular n−gon, the measure of each angle
is ( (n−2)*180/n )
*/

int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        int a;
        cin >> a;
        int x = 180-a;
        if( 360%x == 0 && (360/x >= 3 ) ) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}

