#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    ara[0]=0;
    int l=0,r=0;
    for(int i=1;i<=n;i++) {
        if(ara[i]==0) {
            l=i;
            ans++;
        }
        else {
            r=i-1;
        }
    }
    return 0;
}
