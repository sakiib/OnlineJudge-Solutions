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
    LL x , y;
    cin >> x >> y;
    LL n;
    cin >> n;
    if( n == 1 ) {
        cout << ((x+MOD)%MOD)%MOD << endl;
        return 0;
    }
    if( n == 2 ){
        cout << ((y+MOD)%MOD)%MOD << endl;
        return 0;
    }
    if( n%3 == 0 ) {
        LL val = 0;
        if( n&1 ) val = (y+MOD)%MOD-(x+MOD)%MOD;
        else val = (x+MOD)%MOD-(y+MOD)%MOD;
        cout << ((val+MOD)%MOD)%MOD <<endl;
        return 0;
    }
    if( n%3 == 1 ) {
        LL val = 0;
        if( n&1 ) val = x;
        else val = -x;
        cout << ((val%MOD)+MOD)%MOD <<endl;
        return 0;
    }
    else {
        LL val = 0;
        if( n&1 ) val = -y;
        else val = y;
        cout <<((val+MOD)%MOD)%MOD <<endl;
    }
    return 0;
}

