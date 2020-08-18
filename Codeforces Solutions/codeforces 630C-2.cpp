#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL val[60];

void calc() {
    val[1] = 2;
    for( LL i = 2; i <= 55; i++ ) {
        val[i] = val[i-1]*2;
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    calc();
    cin >> n;
    LL ans = 0;
    for(LL i = 1; i <= n; i++) {
       ans += val[i];
    }
    cout << ans <<endl;
    return 0;
}
