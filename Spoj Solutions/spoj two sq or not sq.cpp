#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(int argc,char const *argv[]) {

    int t;
    scanf("%d",&t);
    while(t--) {
        ll n;
        scanf("%lld",&n);
        ll l=0,r=sqrt(n+10);
        bool found=false;
        while(l<=r) {
            if(l*l+r*r==n) {
                found=true;
                break;
            }
            if(l>r) break;
            while(l*l+r*r<n) l++;
            while(l*l+r*r>n) r--;
        }
        if(found) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
