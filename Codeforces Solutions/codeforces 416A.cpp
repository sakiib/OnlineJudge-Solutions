#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf=1500000000;
ll l=-inf;
ll r=inf;

int main(int argc,char const *argv[]) {
    ll n,num;
    cin>>n;
    string a,b;
    getchar();

    while(n--) {
        cin>>a>>num>>b;
        if(a=="<") {
            if(b=="Y") r=min(r,num-1);
            else l=max(l,num);
        }
        else if(a==">") {
            if(b=="Y") l=max(l,num+1);
            else r=min(r,num);
        }
        else if(a=="<=") {
            if(b=="Y") r=min(r,num);
            else l=max(l,num+1);
        }
        else {
            if(b=="Y") l=max(l,num);
            else r=min(r,num-1);
        }
    }
    if(l<=r) cout<<l<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}
