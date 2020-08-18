#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct seat {
    bool seata , seatb;
    int width;
    int id;
};

priority_queue < seat > Q;

int main( int argc, char const *argv[] ) {
    seat a;
    a.width = 100;
    a.id = 1;
    a.seata = false;
    a.seatb = true;
    Q.push( a );
    seat t = Q.top();
    cout << t.width << " " << t.id << " " << t.seata << " " << t.seatb << endl;
    return 0;
}





