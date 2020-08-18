#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL ara[ 100005 ];

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    sort(ara+1,ara+n+1);
    LL sum = ara[ 1 ] , cnt = 1;
    for( int i = 2; i <= n; i++ ) {
        if( sum <= ara[ i ] ) {
            cnt++;
            sum += ara[ i ];
        }
    }
    cout << cnt << endl;
    return 0;
}
