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

int cnt[10]={0};
int ara[ 2*N ];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        cnt[ ara[i] ]++;
    }
    int ans = min( cnt[2] , cnt[1] );
    cnt[1] -= ans;
    ans += cnt[1]/3;
    cout << ans << endl;
    return 0;
}




