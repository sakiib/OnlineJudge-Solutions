#include <bits/stdc++.h>
using namespace std;

int ara[100005];
int temp[100005];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        temp[i] = ara[i];
    }
    sort(ara+1,ara+n+1);
    for(int i = 2; i <= n; i++ ) {
        if(ara[i] == ara[i-1]) {
            ara[i] ++;
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; i++ ) {
        ans += abs(temp[i]-ara[i]);
    }
    cout << ans <<endl;
    return 0;
}
