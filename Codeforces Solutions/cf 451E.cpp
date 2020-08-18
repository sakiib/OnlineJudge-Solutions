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

LL ara[2*N];
vector<LL> p,k;

bool ps(LL val) {
   LL sq=sqrt(val);
   if(sq*sq==val) return true;
   else return false;
}
int main( int argc, char const *argv[] ) {
    calc();
    LL n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        if(ps(ara[i])) p.push_back(ara[i]);
        else k.push_back(ara[i]);
    }
    if((int)(p.size)==(int)(k.size()) {
       cout<<0<<endl;
       return 0;
    }
    if(p.size()<k.size()) {

    }
    return 0;
}



