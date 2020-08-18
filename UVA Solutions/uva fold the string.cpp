#include <bits/stdc++.h>
using namespace std;

#define Fast_IO ios_base::sync_with_stdio(0); cin.tie(0);

typedef unsigned long long uLL;
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;
const LL INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int cnt[ N ];
int sum;

int main( int argc , char const *argv[] ) {
        string s;
        cin >> s;
        for( int i = 0; i < s.size(); i++ ) cnt[s[i]-'a'+1]++;
        sort( cnt+1 , cnt+26+1 );
        for( int i = 1; i <= 24; i++ ) sum += cnt[i];
        cout << sum << endl;
        return 0;
}






