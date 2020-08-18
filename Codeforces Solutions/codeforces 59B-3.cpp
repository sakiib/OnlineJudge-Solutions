#include <bits/stdc++.h>
using namespace std;

int ara[ 105 ];
vector<int> od , ev;
int ans = 0;

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        if(ara[i]&1) od.push_back( ara[i] );
        else ev.push_back( ara[i] );
    }
    sort(od.rbegin(),od.rend());
    if(od.size() == 0) {
        cout << 0 <<endl;
        return 0;
    }
    if(od.size()%2==0) od.pop_back();
    for( auto x : od ) ans += x;
    for( auto x : ev)  ans += x;
    cout << ans <<endl;
    return 0;
}
