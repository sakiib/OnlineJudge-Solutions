#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define All(V) V.begin(),V.end()
#define Unique(V) sort( All(V)),V.erase( unique( All(V) ),V.end() )
#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , h;
int x[ 2*N ] , y [ 2*N ];
LL d = 0;
int main( int argc , char const *argv[] ) {
        Fast_IO;
        cin >> n >> h;
        for( int i = 1; i <= n; i++ ) cin >> x[i] >> y[i];
        int X = x[1] , Y = h;
        for( int i = 1; i <= n; i++ ) {
                //cout << d << " " << X << " " << Y << endl;
                d += ( y[i] - x[i] );
                if( Y <= 0 ) break;
                if( i != n ) {
                        int dif = x[i+1] - y[i];
                        if( Y < dif ) {
                                d += Y;
                                Y = 0;
                                break;
                        }
                        else {
                                Y -= dif;
                                d += dif;
                        }
                }
                cout << d << " " << X << " " << Y << endl;
        }
        //cout << "Y : " << Y << endl;
        if( Y > 0 ) d += Y;
        cout << d << endl;
        return 0;
}





