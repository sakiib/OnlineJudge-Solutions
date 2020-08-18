#include<bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int n,k;
    cin>>n>>k;
    vector<int> V;
    for(int i=2;i<=n;i++) {
        if(isprime(i)) V.push_back(i);
    }
    int ans=0;
    for(int i=0;i<V.size()-1;i++) {
        if(isprime(V[i]+V[i+1]+1)&&(V[i]+V[i+1]+1)<=n) ans++;
    }
    if(ans>=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
