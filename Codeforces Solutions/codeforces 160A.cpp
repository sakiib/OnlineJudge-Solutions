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
int n;
int half;

int main( int argc, char const *argv[] ) {
    cin >> n;
    int sum = 0;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        sum += ara[i];
    }
    sort(ara+1,ara+n+1);
    half = sum/2;
    int mn = inf;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n ; j++ ) {
            int sum = 0;
            for( int k = i; k <= j ; k++ ) {
                sum += ara[k];
            }
            if( sum > half ) {
                mn = min( mn , (j-i+1) );
            }
        }
    }
    cout << mn <<endl;
    return 0;
}




