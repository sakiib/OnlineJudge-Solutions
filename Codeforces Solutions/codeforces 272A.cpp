#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,f,a,sum=0,x,ans=0;
    int ara[105];
    cin>>n;
    for(int i=1,j=0;i<=101;i++,j+=n) {
        ara[i]=j+i;
    }
    for(int i=0;i<n;i++) {
        cin>>x;
        sum+=x;
    }
    for(int i=1;i<=5;i++) {
        int f=sum+i;
        bool nai=false;
        for(int j=1;j<=101;j++) {
            if(ara[j]==f) {
                nai=true;
                break;
            }
        }
        if(!nai) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
