#include<bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return false;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int a,b,val;
    cin>>a>>b;
    for(int i=a+1; ;i++) {
        if(isprime(i)) {
            val=i; break;
        }
    }
    if(val==b) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
