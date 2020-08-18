#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100005;

LL ara[ N ];

LL Binary_Search( LL val ) {
    LL lo = 0, hi = 100000;
    LL ret = 0;
    while( lo <= hi ) {
        LL mid = (lo+hi)/2;
        LL tot = mid*(mid+1)/2;
        if(tot > val) hi = mid-1;
        else {
            ret = mid;
            lo = mid+1;
        }
    }
    return ret;
}
int main( int argc , char const *argv[] ) {
    LL n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    LL pos = Binary_Search( k );
    cout << ara[pos] <<endl;
    return 0;
}
