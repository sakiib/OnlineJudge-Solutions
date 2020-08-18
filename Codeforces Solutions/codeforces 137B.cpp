#include<bits/stdc++.h>
using namespace std;

int ara[5005];
map<int,bool> M;

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int num;
        scanf("%d",&ara[i]);
        M[ara[i]]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(!M[i]) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
