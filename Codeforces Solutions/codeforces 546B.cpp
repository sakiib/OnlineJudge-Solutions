#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ll k,n,w;
    cin>>k>>n>>w;
    ll cost=k*w*(w+1)/2;
    cout<<(cost<=n?0:cost-n)<<endl;
    return 0;
}
