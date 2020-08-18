#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
       int a,b;
       cin>>a>>b;
       int g=__gcd(a,b);
       if(g==1) {
        cout<<"NO SOLUTION"<<endl;
       }
       else {
        a/=g; b/=g;
        int ans=max(a,b);
        cout<<ans<<endl;
       }
    }
    return 0;
}
