#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc,char const *argv[]) {
    LL a,b;
    cin>>a>>b;
    if(b-a>=10) {
        cout<<0<<endl;
        return 0;
    }
    LL ans=1;
    for(LL i=a+1;i<=b;i++) {
        ans=ans*(i%10)%10;
    }
    cout<<ans<<endl;
    return 0;
}


