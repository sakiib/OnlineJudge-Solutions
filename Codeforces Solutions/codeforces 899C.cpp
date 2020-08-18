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

vector< LL > V;
vector < int > ans;
LL target;

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( LL i = 1; i <= n; i++ ) {
        V.push_back( i );
    }
    if( n == 2 ) {
        cout << 1 <<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    LL tot = n*(n+1)/2;
    LL dif = 0;
    if( tot%2 == 0 ) cout <<0<<endl;
    else cout <<1<<endl;
    target = tot/2;
    int st = 0, en = 0;
    for( int i = 0; i < V.size(); i++ ) {
        LL sum = V[i];
        st = i;
        for(int j = i+1; j < V.size(); j++ ) {
            sum += V[j];
            if( sum == target ) {
                cout <<j-st+1<<" ";
                for( int k = st; k <= j; k++ ) {
                    cout << V[k]<<" ";
                }
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}




