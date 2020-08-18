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

int ara[ N ];
int cnt [ N ] = {0};

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        cnt[ ara[i] ]++;
    }
    int ans = 0;
    ans = cnt[4];
    while( cnt[3] >= 1 && cnt[1] >= 1 ) {
        ans ++;
        cnt[3]-- , cnt[1]--;
    }
    ans += cnt[3];
    cnt[3] = 0;
    while( cnt[2] >= 2 ) {
        ans ++;
        cnt[2]-=2;
    }
    while( cnt[1] >= 4 ) {
        ans ++;
        cnt[1] -= 4;
    }
    while( cnt[2] >= 1 && cnt[1] >= 2 ) {
        ans ++;
        cnt[2] --;
        cnt[1] -= 2;
    }
    int r = cnt[2]*2+cnt[1];
    ans += r/4;
    if( r%4 ) ans ++;
    cout << ans <<endl;
    return 0;
}

