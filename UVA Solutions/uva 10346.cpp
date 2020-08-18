#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,k;
    int ans=0;
    while(scanf("%d%d",&n,&k)!=EOF) {
        ans=n;
        int butt=n;
        int add=0;
        while(true) {
            add+=(butt/k);
            butt%=k;
            butt+=add;
            ans+=add;
            add=0;
            if(butt<k) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
