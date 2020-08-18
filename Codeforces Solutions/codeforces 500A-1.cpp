#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc, char const *argv[]) {
    LL ara[5];
    int t;
    cin >> t;
    while( t-- ) {
    cin >> ara[0] >> ara[1] >> ara[2];
    sort(ara,ara+3);
    LL sum = ara[0]+ara[1]+ara[2];
    cout << min(sum/3,min(sum-ara[0],min(sum-ara[1],sum-ara[2])))<<endl;
    }
    return 0;
}
