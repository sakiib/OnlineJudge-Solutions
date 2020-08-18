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

LL n,a,b;

bool can( LL val ) {
    LL lo = 0 , hi = val;
    while(lo<=hi) {
        LL mid=(lo+hi)/2;
        if(mid*b==val) return true;
        if(mid*b>val) hi=mid-1;
        else lo=mid+1;
    }
    return false;
}
int main( int argc, char const *argv[] ) {
    cin >> n >> a >> b;
    for(LL i=0;i<=10000000;i++) {
        LL x = i;
        LL left = n-a*x;
        if(left<0) break;
        if(can(left)) {
            cout <<"YES"<<endl;
            cout << x <<" "<< (n-a*x)/b <<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}



