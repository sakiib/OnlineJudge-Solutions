#include<bits/stdc++.h>
using namespace std;

int ara[1000005];
int cum[1000005]={0};

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        int temp=i-ara[i];
        temp=max(temp,1);
        cum[temp]++;
        cum[i]--;
    }
    for(int i=1;i<=n;i++) {
        cum[i]+=cum[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(cum[i]==0) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
