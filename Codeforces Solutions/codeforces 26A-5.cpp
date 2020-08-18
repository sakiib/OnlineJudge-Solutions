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

int n;
vector <int> prime;

bool isprime( int num ) {
    for( int i = 2; i*i <= num; i++ ) {
        if( num%i == 0 ) return false;
    }
    return true;
}
void calc( ) {
    for( int i = 2; i <= n; i++ ) {
        if( isprime(i) ) prime.push_back( i );
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    calc( );
    int cnt = 0 , ans = 0;
    for( int i = 2; i <= n; i++ ) {
        cnt = 0;
        int val = i;
        for( int j = 0; j < prime.size(); j++ ) {
            if( val%prime[j] == 0 ) {
                cnt++;
                while( val%prime[j] == 0 ) val /= prime[j];
            }
        }
        if( val > 1 ) cnt++;
        if( cnt == 2 ) ans++;
    }
    cout << ans << endl;
    return 0;
}

