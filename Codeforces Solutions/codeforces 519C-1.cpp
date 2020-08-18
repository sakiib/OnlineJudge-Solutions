#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc,char const *argv[]) {
    LL ex,nb,ans=0;
    cin>>ex>>nb;
    while(ex>0&&nb>0&&nb+ex>=3) {
        if(nb>ex) {
            nb-=2;
            ex--;
        }
        else {
            nb--;
            ex-=2;
        }
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
