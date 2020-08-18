#include<bits/stdc++.h>
using namespace std;

#define ll long long

void NO() {
    cout<<-1<<endl;
    exit(0);
}
int main(int argc,char const *argv[]) {
    ll n,x=50;
    cin>>n;
    if(n<=2) NO();
    if(n==3) {
        cout<<210<<endl;//length 3 ber kore 4 er tar
                        //pattern pawa jabe//E:G-4 length er sesh e 50 ase
        return 0;
    }
    cout<<1;
    for(int i=1;i<=n-4;i++) {
        cout<<0;
        x*=10;
        x%=210;
    }
    printf("%03lld",x);
    return 0;
}
