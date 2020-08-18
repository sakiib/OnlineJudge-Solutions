#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL fact[100010];

void calc() {
    fact[0]=1LL;
    for(LL i=1;i<=9;i++) {
        fact[i]=fact[i-1]*i;
    }
}
int main(int argc,char const *argv[]) {
    calc();
    LL a,b;
    cin>>a>>b;
    if(a==b) {
        cout<<1<<endl;
        return 0;
    }
    if(a==0&&b==0) {
        cout<<1<<endl;
        return 0;
    }
    a%=10;
    b%=10;
    if(a==0||a==1) {
        if(b==1) cout<<1<<endl;
        else if(b==2) cout<<2<<endl;
        else if(b==3) cout<<6<<endl;
        else if(b==4) cout<<4<<endl;
        else cout<<0<<endl;
        return 0;
    }
    b=b%10;
    a=a%10;
    LL x=fact[a];
    LL y=fact[b];
    //cout<<x<<" "<<y<<endl;
    LL z=y/x;
    cout<<(z%10)<<endl;
    return 0;
}



